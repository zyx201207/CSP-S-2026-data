#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt[N],d[N],vis[N];
vector<int> v,g;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	v.pb(-1);g.pb(-1);
	for(int i=1;i<=n;i++) v.pb(-1),g.pb(-1);
	vis[a[n]]=n;
	for(int i=n-1;i>=1;i--){
		v[i]=v[i+1];g[i]=g[i+1];
		if(!vis[a[i]]) vis[a[i]]=i;
		else v[i]=vis[a[i]],g[i]=i;
	}
	for(int i=n;i>=1;i--){
		if(v[i]==-1){
			d[i]++;d[n+1]--;
			continue;
		}
		int l=i;
		while(true){
			if(v[l]==-1){
				d[l]++;d[n+1]--;
				break;
			}
			if(a[l]!=a[v[l]]) d[l]++,d[g[l]]--,l=v[l];
			else l=v[l]; 
		}
	}
	for(int i=1;i<=n;i++) d[i]+=d[i-1],cnt[a[i]]+=d[i];
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}

