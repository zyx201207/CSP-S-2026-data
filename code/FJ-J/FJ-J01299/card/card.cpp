#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int n,m;
int a[N+5],cnt[N+5],to[N+5],vis[N+5];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(vis[a[i]]!=0) to[vis[a[i]]]=i;
		vis[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int l=i;
		if(i==n){
			cnt[a[i]]++;
			continue;
		}
		while(l<=n){
			if(!to[l]){
				cnt[a[l]]++;
				l++;
				continue;
			}
			l=to[l];
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
