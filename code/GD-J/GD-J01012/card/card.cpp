#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20;
int a[N],ans[N];
int vis[N],cnt;//±ê¼Ç 
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<i;j++){
			if(a[j]==a[i]){
				vis[j]=i;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
//			int l,r;
			if(vis[j]>0){
				j=vis[j];
			}
			ans[a[j]]++;
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
