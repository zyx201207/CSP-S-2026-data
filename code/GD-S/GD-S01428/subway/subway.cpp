#include<bits/stdc++.h>
#define int long long
#define f(i,x,n,y) for(int i=x;i<=n;i+=y)
#define f1(i,x,n,y) for(int i=x;i>=n;i-=y)
#define pair pair<int,int>
#define l first
#define r second
using namespace std;
const int N=5e5+5;
int T,t,n,m,x,y,z,k,ans=1e9,sum,cnt,a[N],b[N],vis[505][25];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	while(cin>>t>>n>>m>>k>>T){
		vector<pair>p[505];
		vector<pair>p1[505];
		f(i,1,m,1){
			cin>>a[i];
		}
		f(i,1,n,1){
			cin>>b[i];
			f(j,1,b[i],1){
				cin>>x>>y;
				p[x].push_back({i,y});
				p1[i].push_back({x,y});
			}
		}
		while(T--){
			cin>>x>>y;
			queue<pair>q;
			memset(vis,0x3f3f3f,sizeof(vis));
			q.push({x,a[x]});
			while(q.size()){
				cnt=q.front().l,sum=q.front().r;
				q.pop();
				if(cnt==y){
					ans=min(sum+a[cnt],ans);
					continue;
				} 
				for(pair i:p[cnt]){
					for(pair j:p1[i.l]){
						if(cnt==j.l)continue;
						
						z=sum+i.r+j.r;
						if(vis[cnt][j.l]>z){
							vis[cnt][j.l]=z;
							q.push({j.l,z});
						}
					} 
				}
			}
			cout<<ans<<"\n";
			ans=1e9;
		}
	}


	return 0;
}

