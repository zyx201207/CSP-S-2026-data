#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int t1[N],mp[N];
int ans[N],a[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++){
			if(mp[a[i]])
				for(int j=i-1;j>mp[a[i]];j--)mp[a[j]]=0;
			mp[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
			if(mp[i]>0){
				ans[i]++;
				mp[i]=0;
			}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
