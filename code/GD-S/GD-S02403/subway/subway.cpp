#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N = 505,M = 5e5+5;
int w[M];
vector<int> a[N],t[N];
vector<pair<int,int>> g[M];//1:线路，2:时间 
long long ans,minn = LONG_LONG_MAX;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		if(n<=2&&k==2){
			int p1,p2,p3,p4;
			cin>>p1>>p2>>p3>>p4;
			minn = min(minn,0ll+p2+p4);
		}
		for(int j = 1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			g[x].push_back({i,y});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans = 0ll+w[x]+w[y];
		if(n<=2){
			cout<<ans+minn<<'\n';
		}
		else if(n<=3){
			int z;
			for(z = 1;z<=3;z++){
				if(z!=x&&z!=y){
					break;
				}
			}
			minn = LONG_LONG_MAX;
			for(auto i : g[x]){
				for(auto j : g[y]){
					if(i.first==j.first){
						minn = min(minn,0ll+i.second+j.second);
					}
				}
				long long minn2 = LONG_LONG_MAX;
				for(auto j : g[z]){
					if(i.first==j.first){
						minn2 = min(minn2,0ll+i.second+j.second);
					}
				}
				long long minn3 = LONG_LONG_MAX;
				for(auto i2 : g[z]){
					for(auto j2 : g[y]){
						if(i2.first==j2.first){
							minn3 = min(minn3,0ll+i2.second+j2.second);
							minn = min(minn,minn2+minn3);
						}
					}
				}
			}
			cout<<ans+minn<<'\n';
		}
	}
	return 0;
}

