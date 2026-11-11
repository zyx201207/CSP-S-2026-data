#include <bits/stdc++.h> 
using namespace std;

int n=0,m,nb,nc;
int a[500010],bb[500010],b[500010],c[300010];

int my_find(int x){
	for(int i=1;i<=n;i++){
		if(a[i]==x){
			return i;
		}
	}
	return -1;
}
void my_schm(int i){
	for(int j=i;j<=n;j++){
		a[j]=0;
	}
	n=i;
}

void my_hy(){
	n=0;
	nc=nb;
	for(int i=1;i<=nb;i++){
		 b[i]=bb[i];
	} 
	for(int i=1;i<=n;i++){
		 a[i]=0;
	}
}

void my_f(){
	for(int i=1;i<=n;i++){
		c[a[i]]++;
	}
}
int main(){
	//ÊäÈë 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>nc>>m;
	nb=nc;
	for(int i=1;i<=nc;i++){
		cin>>b[i];
	}
	for(int i=1;i<=nc;i++){
		 bb[i]=b[i];
	} 
	for(int i=1;i<=nc;i++){
		for(int j=i;j<=nc;j++){
			int sum=my_find(b[j]);
			if(sum!=-1){
				my_schm(sum);
				n+=1;
				a[n]=b[j];
			}else{
				n+=1;
				a[n]=b[j];
			}
			if(nc==1){
				break;
			}
		}
		my_f();
		my_hy();
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
