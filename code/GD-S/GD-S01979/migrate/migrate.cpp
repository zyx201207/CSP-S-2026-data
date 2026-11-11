#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,n,t,x[N],d,minn[N],last,to[N];
struct stu{
	int u,cnt;
};
int bfs(){
	int ans=0;
	queue<stu> q;
	q.push({1,0});
	while(!q.empty()){
		int u=q.front().u,cnt=q.front().cnt;
		q.pop();
		if(u>n){
			continue;
		}
		if(minn[u]==cnt){
			to[u]++;
		}
		for(int i=u;x[i]<=x[u]+d;i++){
			q.push({i,cnt+1});
		}
	}
	for(int i=1;i<=n;i++){
		if(to[i]==2){
			ans++;
		}
	}
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}		
		minn[1]=0;
		for(int i=2;i<=n;i++){
			while(x[i]>last){
				minn[i]++;
				last+=d;
			}
			if(minn[i]==0){
				minn[i]=minn[i-1];
			}
		}
		cout<<bfs()<<endl;
	}
	return 0;
}

