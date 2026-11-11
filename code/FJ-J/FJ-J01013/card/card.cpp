#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int vis[500005]={};
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=j; s[a[j]]++;
			}else{
				for(int k=vis[a[j]]+1;k<j;k++){
					if(vis[a[k]]!=0) s[a[k]]--;
					vis[a[k]]=0;
				}
				vis[a[j]]=j;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	cout<<'\n';
	return 0;
}
