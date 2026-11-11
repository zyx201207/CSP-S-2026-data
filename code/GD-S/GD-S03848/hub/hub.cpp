#include<bits/stdc++.h>
using namespace std;
long long n,m,c,t,x,y,ans=INT_MAX,v[100005];
vector<long long> e[100005];
long long bfs(int sx){
	memset(v,0,sizeof(v));
	long long step=1,ans1=0,ans2=0;
	queue<long long> qq,anss;
	qq.push(sx);
	anss.push(0);
	v[sx]=1;
	while(!qq.empty()){
		long long q=qq.front(),aa=anss.front()+1;
		qq.pop(),anss.pop();
		for(int x:e[q] ){
			if(v[x])continue;
			step++;
			if(ans1<=aa)ans2=ans1,ans1=aa;
			else if(ans2<aa)ans2=aa;
			if(step==m)return ans1+ans2;
			v[x]=1;
			qq.push(x);
			anss.push(aa);
		}
	}
}


int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=INT_MAX;
		cin>>n>>m;
		for(int i=1;i<=n-1;i++){
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}	
		for(int i=1;i<=n;i++){
			ans=min(ans,bfs(i));
			//cout<<bfs(i)<<" "; 
		}
		cout<<ans<<endl;
	}
	
	
	
	
	return 0;
}

