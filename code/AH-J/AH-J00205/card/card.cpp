#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int mp[300005];
int st[500005];
int cnt[300005];
int vis[300005];
int lt[300005];
int sum[300005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lt[a[i]]=i;
		if(mp[a[i]]==0){
			mp[a[i]]=i;
		}
		else{
			st[mp[a[i]]]=i;
			mp[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=i){
				cnt[a[j]]++;
				vis[a[j]]=i;
			}	
			if(st[j]){
				j=lt[a[j]]-1;
			}
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
