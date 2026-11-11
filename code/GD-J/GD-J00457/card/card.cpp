#include<iostream>
using namespace std;
int n,m,l[500010],id[300010],num[300010];

void bl(){
	for(int i=1;i<=n;i++){
		int u=0;
		pair<int,int> rubishes[500010];
		rubishes[0]={-1,-1};
		for(int k=1;k<=m;k++) id[k]=0;
		for(int j=i;j<=n;j++){
			num[l[j]]++;
			if(id[l[j]]!=0){
				rubishes[u++]={id[l[j]],j};
				for(int o=id[l[j]];o<j;o++)
					if(id[l[o]]==o)
						id[l[o]]=0;
			}
			id[l[j]]=j;
		}
		for(int j=0;j<u;j++)
			for(int o=rubishes[j].first;o<rubishes[j].second;o++)
				num[l[o]]--;
	}
	for(int i=1;i<=m;i++) cout<<num[i]<<' ';
}

void d13_14(){
	int a=0,b=0;
	for(int i=1;i<=n;i++){
		if(l[i]!=l[n]) a++,b++;
		else if(l[i]==1) a++;
		else b++;
	}
	cout<<a<<' '<<b;
}

void A(){
	int p[300010];
	for(int i=1;i<=m;i++) p[i]=0;
	for(int i=1;i<=n;i++) id[l[i]]=i;
	for(int i=1,j=1;i<=n;i++){
		while(i>id[j]) j++;
		p[j]++;
	}
	for(int i=2;i<=m;i++) p[i]+=p[i-1];
	for(int i=1;i<=m;i++) cout<<p[i]<<' ';
}


void B(){
	int d[5010],len[5010];
	int g=1,h=1;
	for(int i=2;i<=n;i++,g++){
		if(l[i]!=l[i-1]){
			d[h]=l[i-1];
			len[h++]=g;g=0;
		}
	}
	n=h-1;
	for(int i=1;i<=n;i++) l[i]=d[i];
	for(int i=1;i<=n;i++){
		int u=0;
		pair<int,int> rubishes[500010];
		rubishes[0]={-1,-1};
		for(int k=1;k<=m;k++) id[k]=0;
		for(int j=i;j<=n;j++){
			num[l[j]]+=len[i];
			if(id[l[j]]!=0){
				rubishes[u++]={id[l[j]],j};
				for(int o=id[l[j]];o<j;o++)
					if(id[l[o]]==o)
						id[l[o]]=0;
			}
			id[l[j]]=j;
		}
		for(int j=0;j<u;j++)
			for(int o=rubishes[j].first;o<rubishes[j].second;o++)
				num[l[o]]-=len[i];
	}
	for(int i=1;i<=m;i++) cout<<num[i]<<' ';
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool flag=1;
	cin>>n>>m;int s=0;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		if(l[i]<l[i-1]) flag=0;
		if(i!=1 && l[i]!=l[i-1]) s++;
	}
	if(m<=1){cout<<n;return 0;}
	if(m<=2){d13_14();return 0;}
	if(flag){A();return 0;}
	if(n<=5000){bl();return 0;}
	if(s<=4999){B();return 0;}
}
