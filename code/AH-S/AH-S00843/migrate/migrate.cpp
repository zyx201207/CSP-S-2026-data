#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long
int a[2000005],n,d;
bool solve(int,int);
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==13 || c==14){
			if(n>=3) cout<<max(0ll,n-(d/(a[2]-a[1])*2-1))<<endl;
			else cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(solve(i,j)) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
bool solve(int x,int y){
	queue<pair<int,int>> q;
	q.push({x,0});
	int ans=0,minn=1145141919810;
	while(!q.empty()){
		auto b=q.front();
		q.pop();
		int u=b.first,w=b.second;
		if(w>minn) continue;
		if(u==y){
			if(w==minn) ans++;
			else ans=1,minn=w;
		}
		for(int v=u+1;v<=y;v++){
			if(a[v]-a[u]>d) break;
			q.push({v,w+1});
		}
	}
	return ans==2;
}
// S00843
// 24-40pts
