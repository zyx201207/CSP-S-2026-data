#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,vis[N],a[N],ans[N],last[N];
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=1;k<=n;k++){
		memset(vis,0,sizeof(vis));
		for(int i=k;i<=n;i++){
			if(vis[a[i]]>0){
				for(int j=last[a[i]];j<i;j++)if(vis[a[j]]>0)vis[a[j]]--;
			}
			vis[a[i]]++,last[a[i]]=i;
		}
		for(int i=1;i<=m;i++)if(vis[i]>0)ans[i]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
