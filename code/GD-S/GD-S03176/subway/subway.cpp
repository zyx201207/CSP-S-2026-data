#include<bits/stdc++.h>
#define ll long long
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int M=5e5+10;
vector<int> sub[M];
vector<pair<int,ll>> t[M];
ll dist[505][505];
ll w[M];
ll c,n,m,d,q;
int main(){
	/*freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);*/
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	inc(i,1,n){
		inc(j,1,n){
			if(i!=j)dist[i][j]=dist[j][i]=1e18;
		}
	}
	inc(i,1,m)cin>>w[i];
	int a;
	inc(i,1,n){
		cin>>a;
		inc(j,1,a){
			int x;
			ll b;
			cin>>x>>b;
			sub[x].push_back(i);
			t[x].push_back({i,b});
			for(int k=0;k<sub[x].size();k++){
				if(sub[x][k]==i)break;
				ll m1=t[x][k].second;
				int g=sub[x][k];
				dist[g][i]=dist[i][g]=min(dist[i][g],b+m1);
			}
		}
	}
	inc(k,1,n){
		inc(i,1,n){
			if(i==k||dist[i][k]==1e18)continue;
			inc(j,1,n){
				if(i==j||j==k||dist[j][k]==1e18)continue;
				dist[i][j]=dist[j][i]=min(dist[j][i],dist[i][k]+dist[k][j]);
			}
		}
	}
	/*inc(i,1,n){
		inc(j,i+1,n)cout<<dist[i][j]<<" "<<i<<" "<<j<<"\n";
	}*/
	while(q--){
		
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
