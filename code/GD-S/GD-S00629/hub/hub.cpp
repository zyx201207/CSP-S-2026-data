#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> v[1000001];
queue<int> q;
long long dis[1000001];
bool check(unsigned long long x){
	long long cnt,now;
	while(x){
		for(int i=0;i<64;i++){
			if(x&(1<<i)){
				now=i;
				break;
			}
		}
		dis[now+1]=0;
		x=x&(x-1);
		cnt++;	
		q.push(now+1);
	}
	return cnt==k;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(unsigned long long i=0;i<(1<<n);i++){
			memset(dis,0x3f,sizeof dis);
			if(check(i)){
				while(q.size()){
					int now=q.front();
					q.pop();
					for(int i:v[now]){
						if(dis[i]>dis[now]+1){
							q.push(i);
							dis[i]=dis[now]+1;
							ans=min(ans,dis[i]);
						}
					}
				}
			}
			while(q.size())q.pop();
		}
		cout<<ans<<'\n';
	}
} 
