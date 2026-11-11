#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
const int N=505,M=500005;
typedef pair<int,int> P;
int c,n,m,d,q;ll w[M];
ll f[N][N];
vector<P> num[M];
int main(){
	 freopen("subway.in","r",stdin);
	 freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof(f));
	rep(i,1,n)f[i][i]=0;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	} for(int i=1;i<=n;++i){
		int to,val,k;cin>>k;
		rep(j,1,k){
			cin>>to>>val;
			num[to].push_back({i,val});
		}
	}
	
//	rep(i,1,m){
//		cout<<num[i].size()<<':';
//		for(auto s:num[i]){
//			cout<<s.first<<' '<<s.second<<" __ ";
//		} cout<<'\n';
//	}
	
	rep(i,1,m){
		int k=num[i].size();
		rep(l,0,k-1){
			rep(r,0,k-1){
				if(l==r)continue;
				int from=num[i][l].first;ll w1=num[i][l].second;
				int to=num[i][r].first;ll w2=num[i][r].second;
				f[from][to]=min(f[from][to],1ll*w1+w2);
			}
		}
	}
	
//	cout<<"initial:\n";
//	
//	rep(i,1,n){
//		rep(j,1,n){
//			cout<<f[i][j]<<' ';
//		} cout<<'\n';
//	}
	
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				if(i==j||j==k||i==k)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
//	cout<<'\n';
//	cout<<"final:\n";
//	rep(i,1,n){
//		rep(j,1,n){
//			cout<<f[i][j]<<' ';
//		} cout<<'\n';
//	}
	
	ll ans=0;
	 rep(ttt,1,q){
		int l,r;cin>>l>>r;ans=0x7f7f7f7f7f7f7f7fll;
		for(auto s:num[l]){
			int from=s.first,w1=s.second;
			for(auto t:num[r]){
				int to=t.first,w2=t.second;
				ans=min(ans,f[from][to]+w1+w2);
			}
		} cout<<ans+w[l]+w[r]<<'\n';
	}
	return 0;
}
