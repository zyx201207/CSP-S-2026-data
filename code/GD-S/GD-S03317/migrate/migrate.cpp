#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,d,dis[5005];
vector<int> e[5005];
int clec(){
	for(int i=1;i<=n;i++) dis[i]=0x7fffffff;
}
struct la{
	int i,d;
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d){
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			queue<la> q;
			clec();
			dis[i]=0;
			q.push({i,dis[i]}); 
			while(q.size()>0){
				la u=q.front();
				q.pop();
				for(int j=0;j<e[u.i].size();j++){
					if(dis[e[u.i][j]]==dis[u.i]+1){
						ans++;
					}
					if(dis[e[u.i][j]]!=0x7fffffff){
						continue;
					}
					q.push({e[u.i][j],u.d+1});
					dis[e[u.i][j]]=dis[u.i]+1;
				}
			}
		}
		cout<<ans<<"\n";
	}
} 
