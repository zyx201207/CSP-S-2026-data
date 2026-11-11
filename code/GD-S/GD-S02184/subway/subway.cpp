#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
int w[N],a[N],t[N],x[N],y[N];
int vis[N];
int ans;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>t[i];
		vis[t[i]]++;
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(vis[t[n]]==n){
		for(int i=1;i<=n;i++){
		    ans+=t[i];
	    }
	    cout<<ans;
	    return 0;
	}
	return 0;
} 
