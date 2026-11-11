#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
int w[500020];
vector<int> a[520];
vector<int> t[519];
ll val[520][520];
ll dis[520][520];
vector<int> tra[500020];
struct da{
	int a, t;
	bool operator <(const da &o){
		return a<o.a;
	}
};
vector<da> dat[520];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(val,0x3f,sizeof(val));
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll rr,rd;
		cin>>rr;
		for(int j=0;j<rr;j++){
			int rd1,rd2;
			cin>>rd1>>rd2;
			dat[i].push_back({rd1,rd2});
		}
		sort(dat[i].begin(),dat[i].end());
		for(int j=0;j<rr;j++){
			rd=dat[i][j].a;
			tra[rd].push_back(i);
			a[i].emplace_back(rd);
			rd=dat[i][j].t;
			for(int k=0;k<(int)tra[a[i][j]].size()-1;k++){
				val[i][tra[a[i][j]][k]]
				=min(val[i][tra[a[i][j]][k]],
				rd+
				t[tra[a[i][j]][k]]
				[lower_bound(a[tra[a[i][j]][k]].begin(),a[tra[a[i][j]][k]].end(),a[i][j])
				-a[tra[a[i][j]][k]].begin()]
				);
				val[tra[a[i][j]][k]][i]=val[i][tra[a[i][j]][k]];
			}
			t[i].emplace_back(rd);
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=min(dis[i][j],val[i][j]);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int x,y;
	while(q--){
		cin>>x>>y;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<(int)tra[x].size();i++){
			for(int j=0;j<(int)tra[y].size();j++){
				ans=min(ans,
				dis[tra[x][i]][tra[y][j]]+
				t[tra[x][i]]
				[lower_bound(a[tra[x][i]].begin(),a[tra[x][i]].end(),x)
				-a[tra[x][i]].begin()]
				+
				t[tra[y][j]]
				[lower_bound(a[tra[y][j]].begin(),a[tra[y][j]].end(),y)
				-a[tra[y][j]].begin()]
				);
				
			/*	cout<<tra[x][i]
				<<"  "<<tra[y][j]<<endl;
				cout<<a[tra[x][i]]
				[lower_bound(t[tra[x][i]].begin(),a[tra[x][i]].end(),x)
				-a[tra[x][i]].begin()]<<" "<<t[tra[y][j]]
				[lower_bound(a[tra[y][j]].begin(),a[tra[y][j]].end(),y)
				-a[tra[y][j]].begin()]<<endl;*/
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
}
/*
2h 8min
*/
