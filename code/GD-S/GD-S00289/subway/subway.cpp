#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],k[505],x,y,ia,it;
vector<int>a[205],t[205];
struct Station {
	int id,line;
	bool operator <(const Station &oth) const {
		if(id!=oth.id) {
			return id>oth.id;
		}
		else {
			return line>oth.line;
		}
	}
};
map<Station,int>mp;
long long dis[10005][10005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
		mp[{i,0}]=i;
	}
	
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++) {
			cin>>ia>>it;
			a[i].push_back(ia);
			t[i].push_back(it);
			m++;
			mp[{a[i][j],i}]=m;
		}
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=m;j++) {
			if(i==j) dis[i][j]=0;
			else dis[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=k[i];j++) {
			dis[a[i][j]][mp[{a[i][j],i}]]=dis[mp[{a[i][j],i}]][a[i][j]]=t[i][j];
		}
		for(int j=2;j<=k[i];j++) {
			dis[mp[{a[i][j-1],i}]][mp[{a[i][j],i}]]=dis[mp[{a[i][j],i}]][mp[{a[i][j-1],i}]]=0;
		}
	}
	//floyd
	for(int k=1;k<=m;k++) {
		for(int i=1;i<=m;i++) {
			if(i==k||dis[i][k]==INT_MAX) continue;
			for(int j=1;j<=m;j++) {
				if(j==k||i==j||dis[k][j]==INT_MAX) continue;
				if(dis[i][j]>dis[i][k]+dis[k][j]) {
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++) {
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<"\n";
	}
	return 0;
}
