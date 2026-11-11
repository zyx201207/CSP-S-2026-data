#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[200006];
int dis[200006];
int kind[200006];
//int pa[100001];''
vector<int> v[200006];
void spfa(int s,int n){
	for(int i=1;i<=n;i++){
		dis[i]=1e18;
		kind[i]=0;
	}
	dis[s]=0;
	queue<int> q;
	q.push(s);
	kind[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int e:v[x]){
			if(dis[e]>dis[x]+1){
				dis[e]=dis[x]+1;
				kind[e]=kind[x];
				q.push(e);
			}
			else if(dis[e]==dis[x]+1){
				kind[e]++;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==j)continue;
				if(abs(x[i]-x[j])<=d){
					v[i].push_back(j);
				}
				else{
					break;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			spfa(i,n);
			for(int j=i+1;j<=n;j++){
				if(kind[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
