#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int a[N];
struct node{
	int to,pre;
}e[2*N];
int k=0;
int p[N];
void add(int x,int y){
	e[++k].pre=p[x];
	e[k].to=y;
	p[x]=k;
}
int dis[N];
int ans[N];
void dj(int x){
	priority_queue < pair<int,int >,vector< pair<int,int > > , greater<pair<int,int >> >qq;
	qq.push({0,x});
	dis[x]=0;
	while(!qq.empty()){
		int h=qq.top().second;
		qq.pop();	
		for(int i=p[h];i;i=e[i].pre){
			int to=e[i].to;
			if(dis[to]>dis[h]+1){
				dis[to]=dis[h]+1;
				qq.push({dis[to],to});
				ans[to]=0;
			}
			else if(dis[to]==dis[h]+1){
				ans[to]++;
				qq.push({dis[to],to});
			}
		}
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		k=0;
		int n,d;
		cin>>n>>d;
		vector<int> v;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			v.push_back(a[i]);
			e[i].pre=0;
			e[i].to=0;
			p[i]=0;
			ans[i]=0;
			dis[i]=0x3f3f3f3f;
		}
		for(int i=1;i<=n;i++){
			int id,iid;
			if(v[n-1]<=a[i]+d){
				id=n;
			}
			else id=min(n,upper_bound(v.begin(),v.end(),a[i]+d)-v.begin());
			if(v[0]>=a[i]-d){
				iid=1;
			}
			else iid=max(1ll,lower_bound(v.begin(),v.end(),a[i]-d)-v.begin()+1);
			for(int j=iid;j<=id;j++){
				if(i==j)continue;
				add(i,j);
			}
		}
		int aaa=0;
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++){
				dis[j]=0x3f3f3f3f;
				ans[j]=0;
			}
			dj(i);
			for(int j=i+1;j<=n;j++){
				if(ans[j]==1){
					aaa++;
				}
			}
		}
		cout<<aaa<<"\n";
	}
	return 0;
}
