#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[500010],ls[500010],f[500010]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int j=0;j<=n+5;++j) f[j]=0,ls[j]=0;
		for(int j=i;j<=n;++j){
			if(f[a[j]]!=0) for(int k=f[a[j]];k<=j;++k) f[ls[k]]=0,ls[k]=0;
			f[a[j]]=j,ls[j]=a[j];
		}
		for(int j=1;j<=n;++j) if(ls[j]!=0) ans[ls[j]]+=1;
/*		for(int j=1;j<=n;++j) cout<<ls[j]<<' ';
		cout<<'\n';
		cout<<'\n';
		for(int j=1;j<=m;++j) cout<<f[j]<<' ';
		cout<<'\n';
		cout<<'\n';
		cout<<'\n';*/
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<' ';
	return 0;
}
