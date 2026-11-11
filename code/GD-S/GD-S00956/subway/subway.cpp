#include<bits/stdc++.h>
#define int long long
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define frep(i,s,t) for(int i=s;i>=t;i--)
#define rep1(i,s,t) for(int i=s;i<t;i++)
#define frep1(i,s,t) for(int i=s;i>t;i--)
#define set(ai,k) memset(ai,k,sizeof(ai))
#define srt(ai,n) sort(ai+1,ai+1+n)
#define csrt(ai,n,cmp) sort(ai+1,ai+1+n,cmp)
#define pb push_back
using namespace std;
const int N=505,M=5e5+5;
bool st;
int c,n,m,d,q,ai[M][25],wi[M],nm[N],a,b,f[N][N],l,r,ans;
vector<int>vi[N],mi[M];
bool en;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)cin>>wi[i],mi[i].pb(0);
	rep(i,1,n){
		cin>>nm[i];
		rep(j,1,nm[i]){
			cin>>a>>b;
			mi[a].pb(i);
		//	cout<<"Y "<<a<<" "<<i<<endl;
			ai[a][mi[a].size()-1]=b;
		}
	}
	set(f,32);
	rep(i,1,n)f[i][i]=0;
	rep(i,1,m){
		rep1(j,1,mi[i].size())rep1(k,j+1,mi[i].size()){
//			cout<<"yoo "<<i<<" "<<mi[i][j]<<" "<<mi[i][k]<<endl;
			f[mi[i][k]][mi[i][j]]=f[mi[i][j]][mi[i][k]]=min(f[mi[i][j]][mi[i][k]],ai[i][j]+ai[i][k]);
		}
	}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		cin>>l>>r;ans=1e15;
		rep1(j,1,mi[l].size())rep1(k,1,mi[r].size())
			ans=min(ans,ai[l][j]+ai[r][k]+f[mi[l][j]][mi[r][k]]);
		cout<<ans+wi[l]+wi[r]<<endl;
	}
//	cout<<(&st-&en)/1024.0/1024.0<<endl;
}
