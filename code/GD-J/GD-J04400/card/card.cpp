#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500007],nxt[500007],cnt[300007];
unordered_map<int,int> mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(mp[a[i]])nxt[mp[a[i]]]=i;
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!nxt[j])cnt[a[j]]++;
			else j=nxt[j]-1;
		}
	}
	for(int i=1;i<=m;i++){
		if(i<m)cout<<cnt[i]<<" ";
		else cout<<cnt[i];
	}
	return 0;
}
