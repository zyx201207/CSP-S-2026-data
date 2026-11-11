#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define ll long long
#define pb push_back
#define vi vector<int>
#define fi first
#define se second
using namespace std;

const int N=20;
int cid,T;
vi g[N];
int n,k;
bool st[N];
int uu[N],vv[N];
bool ok[N];
int d[N];
int dis(){
	queue<int>q;
	rep(i,1,n)d[i]=1e9,ok[i]=0;
	rep(i,1,n)if(st[i])q.push(i),d[i]=0,ok[i]=1;
	while(!q.empty()){
		int t=q.front();q.pop();
		rep(i,0,(int)g[t].size()-1){
			int v=g[t][i];
			if(!ok[v]){
				ok[v]=1;
				d[v]=d[t]+1;
				q.push(v);
			}
		}
	}
	int mx=0;
	rep(i,1,n)mx=max(mx,d[i]);
	return mx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

	cin>>cid>>T;
	while(T--){
		cin>>n>>k;
		rep(i,1,n)g[i].clear();
		rep(i,2,n){
			int u,v;cin>>u>>v;
			g[u].pb(v),g[v].pb(u);
			uu[i]=u,vv[i]=v;
		}
		int ans=n;
		rep(i,0,(1<<n)-1){
			int c=0;
			rep(j,1,n)st[j]=0;
			rep(j,0,n-1)if(i>>j&1)++c;
			if(c!=k)continue;
			rep(j,0,n-1)if(i>>j&1)st[j+1]=1;
			int t=c;
			rep(j,2,n)if(st[uu[j]]&&st[vv[j]])t-=1;
			if(t<=2){
				ans=min(ans,dis());
			}
		}
		cout<<ans<<'\n';
	}

    return 0;
}



//guanzhufalidamiao,xiexiemiao
