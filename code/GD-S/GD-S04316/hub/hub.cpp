#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,k,v[100],vis[100],ans,cc,vv[100];
vector<ll>a[100];
ll dfs1(ll p,ll cnt){
	ll i,j;
	vv[p]=1;
	if(vis[p]==1) return cnt;
	ll num=1e18;
	for(i=0;i<a[p].size();i++){
		if(vv[a[p][i]]==1) continue;
		num=min(num,dfs1(a[p][i],cnt+1));
	}
	return num;
}
void dfs(ll p,ll cnt,ll o){
	ll i,j;
    if(cnt<0) return;
	if(cnt==0&&o==2){
		cc=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++) vv[j]=0;
			cc=max(cc,dfs1(i,0));
		} 
		ans=min(ans,cc);
		return;
	}
	if(o==1)
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) vis[j]=v[j];
		if(vis[i]==0) {
		vis[i]=1;
		dfs(i,cnt-1,2);
		vis[i]=0;
	    }
	}
	if(o==1)
	for(i=0;i<a[p].size();i++){
		if(v[a[p][i]]==0){
			v[a[p][i]]=1;
			dfs(a[p][i],cnt-1,1);
			v[a[p][i]]=0;
		}
	}
	if(o==2)
	for(i=0;i<a[p].size();i++){
		if(vis[a[p][i]]==0){
			vis[a[p][i]]=1;
			dfs(a[p][i],cnt-1,2);
			vis[a[p][i]]=0;
		}
	}
}
int main(){
	ll i,j,k;
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c<=3){
	while(t--){
		cin>>n>>k;
		ans=1e18;
		for(i=1;i<=n;i++) a[i].clear();
		for(i=1;i<n;i++){
			ll x,y;
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++) v[j]=0;
			v[i]=1;
			dfs(i,k-1,1);
		}
		cout<<ans<<"\n";
	}
	return 0;
    }
    while(t--){
    	cin>>n>>k;
		ans=1e18;
		for(i=1;i<n;i++){
			ll x,y;
			cin>>x>>y;
		}
		if(k<(n-1)/2){
			cout<<((n-1)/2+1-k+3)/4+1<<"\n";
			continue;
		}
		if(k==n) cout<<"0\n";
		else cout<<"1\n";
	}
	return 0;
}
