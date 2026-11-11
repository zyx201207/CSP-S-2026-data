#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[2005],mp[2005][2005],k,qi,zh,vis[2005];
struct station {
	ll a,t,ro;
}s[2005][2005];
queue<station> r;
station x;
void bfs(){
	x.a=qi;
	x.t=w[qi];
	vis[qi]=1;
	r.push(x);
	while(!r.empty()){
		for(int i=1;i<m;i++){
			if(vis[i]==0&&mp[r.front().a][i]!=0){
				x.a=i;
				x.ro=mp[r.front().a][i];
				if(r.front().a==qi) x.t+=s[qi][mp[r.front().a][i]].t+s[i][x.ro].t;
				else if(r.front().a==x.ro) x.t=r.front().t+s[i][x.ro].t;
				else if(r.front().a!=x.ro) x.t=r.front().t+s[i][r.front().ro].t+s[i][x.ro].t;
				r.push(x);
				if(x.a==zh) {
					cout<< x.t+w[i];
					return;
				} 
			}
		}
		r.pop();
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
		 cin>>s[j][i].a>>s[j][i].t;
		 for(int j=2;j<=k;j++)
		  mp[j-1][j]=i;
	}
	for(int i=1;i<=q;i++) {
		cin>>qi>>zh;
		bfs();
		cout<<"\n";
	}
	return 0;
}

