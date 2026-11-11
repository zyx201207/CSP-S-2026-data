#include<bits/stdc++.h>
using namespace std;
long long n,d;
vector<long long>a(n+1);
bool vis[200006];
struct node{
	long long idx,sum; 
};
int dfs(long long u,long long v,int sum){
	vector<long long> d1[1005];
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	for(int i=1;i<=d;i++){
		d1[u].push_back(a[u+i]);
	}
	queue<node> q;
	q.push({a[u],0});
	vis[u]=1;
	int ans=0,cnt=1e9;
	while(!q.empty()){
		node t=q.front();
		q.pop();
		if(t.idx==a[v]&&cnt>=t.sum){
			ans++;
			cnt=t.sum;
		}
		for(int i=0;i<d1[t.idx].size();i++){
			int to=d1[t.idx][i];
			if(vis[to]){
				vis[to]=1;
				q.push({to,t.sum+1});
			}
		}
	}
	return ans;
}
int mian(){
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
 	long long c,T;
 	cin>>c>>T;
 	while(T--){
 		
 		cin>>n>>d;
 		for(int i=1;i<=n;i++){
 			cin>>a[i];
 			
		 }
		 
		 long long ans=0;
		 for(int i=1;i<=n;i++){
		 	for(int j=i+1;j<=n;j++){
		 		
		 		if(dfs(i,j,0)==2){
		 			ans++;
				 }
			 }
		 }
		cout<<ans<<endl;
	 }
	fclose(stdin);
	fclose(stdout);
 	return 0;
 }
