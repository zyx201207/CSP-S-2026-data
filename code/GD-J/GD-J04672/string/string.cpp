#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200007];
char c[200007];
pair<int,char> na[200007];
int p;
pair<int,char> fin[400007];
pair<int,char> fen[400007];
map<int,int> line;
int l[400007];
int p1,p2,p3;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		scanf("%s",c+i);
		sum=sum+a[i];
	}
	int flat=0;
	for(int i=1;i<=n;i++){
		if(c[i]==c[i+1]){
			flat=flat+a[i];
		}
		else{
			p++;
			na[p]={flat+a[i],c[i]};
			flat=0;
		}
	}
	int s=0;
	bool flag=0;
	if(sum%2==0){
		for(int i=1;i<=p;i++){
			s=s+na[i].first;
			if(s>sum/2&&flag==0){
				p1++;
				fin[p1]={na[i].first-(s-sum/2),na[i].second};
				p1++;
				fin[p1]={s-sum/2,na[i].second};
				flag=1;
			}
			else if(s==sum/2){
				p1++;
				fin[p1]={na[i].first,na[i].second};
				flag=1;
			}
			else{
				p1++;
				fin[p1]=na[i];
			}
			line[s]++;
			if(line[s]==1){
				p2++;
				l[p2]=s;
			}
		}
	}
	else{
		for(int i=1;i<=p;i++){
			s=s+na[i].first;
			if(s>(sum+1)/2&&flag==0){
				if(na[i].first-(s-(sum+1)/2)-1>=1){
					p1++;
					fin[p1]={na[i].first-(s-(sum+1)/2)-1,na[i].second};
				}
				p1++;
				fin[p1]={s-(sum+1)/2,na[i].second};
				flag=1;
			}
			else if(s==(sum+1)/2){
				p1++;
				fin[p1]={na[i].first-1,na[i].second};
				flag=1;
			}
			else{
				p1++;
				fin[p1]=na[i];
			}
			if(s<sum&&s!=0){
				line[s]++;
				if(line[s]==1&&s!=sum){
					p2++;
					l[p2]=s;
				}
			}
		}
	}
	for(int i=1;i<=p2;i++){
		line[sum-l[i]]++;
		if(line[sum-l[i]]==1&&sum-l[i]!=0&&sum-l[i]!=sum){
			p2++;
			l[p2]=sum-l[i];
		}
	}
	sort(l+1,l+p2+1);
	int s1=0,sl=1;
	for(int i=1;i<=p1;i++){
		s1=s1+fin[i].first;
		while(s1>=l[sl]&&sl<=p2){
			p3++;
			fen[p3]={l[sl]-l[sl-1],fin[i].second};
			sl++;
		}
	}
	int l=1,r=p3;
	for(int i=1;i<=(p3+1)/2;i++){
		if(fen[l].second!=fen[r].second){
			ans=ans+fen[l].first;
		}
		l++;
		r--;
	}
	printf("%lld",ans);
	return 0;
}
