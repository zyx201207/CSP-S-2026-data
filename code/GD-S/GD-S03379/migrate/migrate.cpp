#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
#define Endl "\n",void()
#define End void()
#define make make_pair
namespace kong{bool st;}
const int N=5005;
int n,d,id;
ll a[N],q[N],res=0x3f3f3f,cnt=0,ans=0;
void bfs(int st,int ed){
	deque<pair<ll,ll> > q;
	q.push_back(make(st,0));
	while(!q.empty()){
		auto now=q.front();
		q.pop_front(); 
		if(now.first==ed){
			if(res==now.second) cnt++;
			else if(res>now.second) res=now.second,cnt=1;
			continue;
		}
		for(int i=now.first+1;i<=ed;i++){
			if(a[i]-a[now.first]<=d){
				q.push_back(make(i,now.second+1));
			}else break;
		} 
	}
	if(cnt==2) ans++;
	return End;
}
void solve1(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			res=0x3f3f3f,cnt=0;
			bfs(i,j);
		}
	}
	return cout<<ans<<Endl;
}
void solve2(){
	vector<vector<ll> > f;
	vector<vector<ll> > g;
	f.resize(n+1);
	g.resize(n+1);
	for(int i=1;i<=n;i++) f[i].resize(n+1);
	for(int i=1;i<=n;i++) g[i].resize(n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=LLONG_MAX,g[i][j]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d) f[i][j]=g[i][j]=1;
			else break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]==LLONG_MAX) cerr<<"X ";
			else cerr<<f[i][j]<<" ";
		}
		cerr<<endl;
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i+len<=n;i++){
			int j=i+len;
			for(int k=i+1;k<j;k++){
				if(i==1&&j==5){
					cerr<<i<<" "<<j<<" "<<k<<" ";
					if(f[i][k]==LLONG_MAX) cerr<<"X ";
					else cerr<<f[i][k]<<" ";
					if(f[k][j]==LLONG_MAX) cerr<<"X ";
					else cerr<<f[k][j]<<" ";
					cerr<<endl;
					cerr<<"dis :: "<<a[k]-a[i]<<" "<<a[j]-a[k]<<" with "<<d<<endl;
				}
				if(f[i][k]!=LLONG_MAX&&f[k][j]!=LLONG_MAX){
//					if(i==1&&j==5) cerr<<"INIT\n";
					if(f[i][k]+f[k][j]==f[i][j]){
						g[i][j]+=g[i][k]*g[k][j];
						if(i==1&&j==5) cerr<<k<<" been add , now::"<<g[i][j]<<Endl;
					}else{
						if(f[i][k]+f[k][j]<f[i][j]){
							f[i][j]=f[i][k]+f[k][j],g[i][j]=g[i][k]*g[k][j];
							if(i==1&&j==5) cerr<<k<<" been add , now::"<<g[i][j]<<Endl;
						}
					}
				}
			}
		}
	}
	cerr<<"----------------\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]==LLONG_MAX) cerr<<"X ";
			else cerr<<f[i][j]<<" ";
		}
		cerr<<endl;
	}
	cerr<<"then:: \n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cerr<<g[i][j]<<" ";
		cerr<<endl;
	}
	ll ans=0;
	cerr<<f[1][5]<<" "<<f[1][6]<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(g[i][j]==2) ans++;
		}
	}
	cerr<<ans<<endl; 
	return cout<<ans<<Endl;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(id==1||id==2||id==0) return solve1();
	if(id==3||id==4||id==5||id==6||id==0) return solve2();
	return End;
}
namespace kong{bool ed;double MB(){return abs(&st-&ed)*1.0/1024/1024;}}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _=1;
	cin>>id>>_;
	while(_--) solve(); 
	cerr<<endl<<kong::MB()<<endl;
	return 0;
}
