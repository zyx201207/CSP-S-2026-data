#include<bits/stdc++.h>
#define int long long
using namespace std;
int k,n,i,j,l,m,t;
int a[1000000],b[1000000][33],c[32],p[10000001],ans=1073741824;
void cl(int k,int i){
	while(k>1){
		int l=2,u=1;
		while(k>=l)l*=2,u++;
		if(l!=2)l/=2;
		k-=l;
		b[i][u]=1;
		c[u]++;
	}
	b[i][1]=k;
}
void gg(int o){
	for(int i=1;i<=n;i++){
		if(p[i]==0&&b[i][o]==0){
			p[i]=1;
		}
		if(p[i]==0&&b[i][o]==1){
			for(j=1;j<=30;j++){
				if(b[i][j]==1)c[j]++;
			}
		}
	}
}
main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cl(a[i],i);
	}
	for(i=30;i>=1;i--){
		if(c[i]>=m){
			for(j=1;j<=30;j++)c[j]=0;
			gg(i);
		}
	}
	for(i=1;i<=n;i++){
		if(p[i]==0&&t==0){
			t=1;
			ans=a[i];
		}
		else{
			if(p[i]==0)ans=(ans&a[i]),t++;
		}
		if(t==m)break;
	}
	cout<<ans;
	return 0;
}
