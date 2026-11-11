#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> ans(m+1,0);
	for(int i=1;i<=n;i++){
		vector<int> vis(n+1,0),pos(n+1,0);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				int st=pos[a[j]];
				for(int k=st;k<j;k++) vis[a[k]]=0;
			}
			vis[a[j]]=1;
			pos[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(vis[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
