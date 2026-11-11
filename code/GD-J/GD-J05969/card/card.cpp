#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maze[500025],dis[300015],ans[300015];
bool f[300015];
stack<int>q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>maze[i];
		dis[maze[i]]++;
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof f);
		for(int j=i;j<=n;j++){
			if(f[maze[j]]==true){
				while(q.top()!=maze[j]){
					f[q.top()]=false;
					q.pop();
				}
			}
			else{
				q.push(maze[j]);
				f[maze[j]]=true;
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
		dis[maze[i]]--;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
