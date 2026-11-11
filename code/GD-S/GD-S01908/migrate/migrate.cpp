#include<bits/stdc++.h>
#define INF 2e18
#define endl '\n'
#define int long long
#define fi first
#define se second
#define pb push_back
#define mem(x,v) memset(x,v,sizeof x)
using namespace std;
const int N = 2e6+5;

//17:09 48pts
int c,T,n,d,ans;
int x[N],to[N],vis[N],dis[N],tot[N];

void bfs(int s){
	for(int i=1;i<=n;i++)dis[i]=INF,tot[i]=0,vis[i]=0;
	dis[s]=0,tot[s]=1;
	
	for(int u=s;u<=n;u++){
		for(int v=u+1;v<=to[u];v++){
			if(dis[v]>dis[u]+1)dis[v]=dis[u]+1,tot[v]=tot[u];
			else if(dis[v]==dis[u]+1)tot[v]+=tot[u];
		}
	}
	for(int v=s;v<=n;v++)if(tot[v]==2)ans++;
}
void solve(){
	cin>>n>>d,ans=0;
	for(int i=1;i<=n;i++)cin>>x[i],to[i]=i;
	if(1<=c&&c<=10){
		for(int i=1;i<=n;i++){while(x[to[i]]-x[i]<=d)to[i]++;to[i]--;}
		for(int i=1;i<=n;i++)bfs(i);cout<<ans<<endl;
	}
	
	if(c==11||c==12){
		int dd=x[2]-x[1];
		int num=d/dd,t=2*num-1;
		if(num<=1)cout<<0<<endl;
		else cout<<max(0ll,n-t)<<endl;
	}
	if(c==13||c==14){
		int a,b;
		for(int i=1;i<=n;i++)if(x[i]-x[1]<=d&&x[n]-x[i]<=d){a=i;break;}
		for(int i=n;i>=1;i--)if(x[i]-x[1]<=d&&x[n]-x[i]<=d){b=i;break;}
		int len=b-a+1;
		if(len!=2)cout<<0<<endl;
		else cout<<(a-1)*(n-b)<<endl;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(cin>>c>>T;T--;)solve();return 0;
}
