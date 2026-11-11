#include<bits/stdc++.h>
#define int long long
#define N 2000006
using namespace std;

struct Edge{int v,next;}e[N*2];int head[N],tot;
void add(int u,int v){e[++tot]={v,head[u]};head[u]=tot;}

int n,k;

bool check(int k){
	
	return true;
}

void solve(){
	cin>>n>>k;for(int i=0;i<=n;i++)head[i]=0;tot=0;
	for(int i=1;i<n;i++){int u,v;cin>>u>>v;add(u,v);add(v,u);}
	int l=0,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	int c,T;cin>>c>>T;while(T--)solve();
	return 0;
}
