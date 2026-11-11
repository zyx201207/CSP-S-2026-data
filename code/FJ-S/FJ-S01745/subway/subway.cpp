# include <bits/stdc++.h>
# define N 500010
# define ll long long
using namespace std;
struct D {
	ll sum; int xl,jd;
	bool operator < (const D &v) const {
		return sum>v.sum;
	}
};
int c,n,m,d,Q,a[N],id[510][510],k[510],b[510][510],t[510][510];
vector<pair<int,int>>ty[N];
priority_queue<D>q;
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
	  cin>>k[i];
	  for(int j=1;j<=k[i];j++)
	    cin>>b[i][j]>>t[i][j],ty[b[i][j]].push_back(make_pair(i,j));
	}
	int x,y;
	while(Q--) {
	  cin>>x>>y; 
	  memset(id,0,sizeof(id));
	  while(q.size()) q.pop();
	  for(auto i:ty[x]) 
		q.push(D{t[i.first][i.second],i.first,i.second});
	  ll ans=0;
	  while(q.size()) {
	    D u=q.top(); q.pop();
	    if(id[u.xl][u.jd]) continue;
	    id[u.xl][u.jd]=1;
	    if(b[u.xl][u.jd]==y) {
	      ans+=u.sum;
	      break;
		}
	    for(auto i:ty[b[u.xl][u.jd]]) {
	      if(b[i.first][i.second]==y)
	        q.push(D{u.sum+t[u.xl][u.jd]+t[i.first][i.second]+t[i.first][i.second],i.first,i.second});
	      else 
	        q.push(D{u.sum+t[u.xl][u.jd]+t[i.first][i.second],i.first,i.second});
		}
		for(int i=1;i<=k[u.xl];i++)
	      if(b[u.xl][i]==y)
	       q.push(D{u.sum+t[u.xl][i],u.xl,i});
	      else 
	       q.push(D{u.sum,u.xl,i});
	  }
	  cout<<ans+a[x]+a[y]<<'\n';
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3

