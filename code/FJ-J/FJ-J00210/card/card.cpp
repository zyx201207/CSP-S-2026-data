#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[20005],t[100005];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=500&&m<=200){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) vis[j]=1;
//			memset(vis,1,sizeof vis);
			for(int j=i;j<=n;j++){
				if(vis[j]==0) continue;
				bool b=0; int x=-1;
				for(int k=j-1;k>=i;k--){
					if(a[k]==a[j]&&vis[k]){
						b=1; x=k;
						break;
					}
				}
				if(!b) continue;
				for(int k=j-1;k>=x;k--) vis[k]=0;
			}
//			cout<<i<<"\n";
			for(int j=i;j<=n;j++){
				t[a[j]]+=vis[j];
			}
//			for(int j=1;j<=m;j++) cout<<t[j]<<' ';
//			cout<<"\n";
		}
		for(int i=1;i<=m;i++) cout<<t[i]<<' ';
	}
	else{
		for(int i=1;i<=n;i++) t[i]++;
		for(int i=1;i<=m;i++) cout<<t[i]<<' ';
	}
	return 0;//誓死效忠绝区0!!! 挽昼大人万岁!!!
}
