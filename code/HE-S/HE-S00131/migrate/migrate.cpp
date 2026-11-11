#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int N=5e5+5;
long long c,t,n,d,x[N],dis[N],vis[N],in[N];
vector<int> a[N];
priority_queue<long long> q;
bool check(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) in[i]=1;
	dis[x]=0;
	q.push(x);
	while(q.size()){
		int f=q.top();
		q.pop();
		if(vis[f]) continue;
		vis[f]=1;
		for(int i=0;i<a[f].size();i++){
			int t=a[f][i];
			if(dis[t]>dis[f]+1){
				
				dis[t]=dis[f]+1;
				in[t]=1;
				q.push(t);
			}
			else if(dis[t]==dis[f]+1){
				in[t]+=in[f];
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]>d) break;
				a[i].push_back(j);
				a[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			check(i);
			for(int j=i+1;j<=n;j++){
				ans+=(in[j]-in[i]==2);
			}
		}
		cout<<ans<<"\n";
	}//what can i say
	return 0;
}
