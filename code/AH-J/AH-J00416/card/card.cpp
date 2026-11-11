#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool vis[300005];
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		//cout<<vis[i]<<" ";
		for(int j=i;j<=n;j++){
			//cout<<vis[a[j]]<<" "<<q.size()<<endl;
			if(!vis[a[j]]){
				q.push(a[j]);
				vis[a[j]]=1;
			}else{
				//cout<<q.size()<<endl;
				while(q.top()!=a[j]){
					q.pop();
					//if(q.top()==a[j]){break;}
				}
				q.pop();
				q.push(a[j]);
			}
		}
		while(!q.empty()){
			//cout<<q.top()<<endl;
			//cout<<21;
			//cout<<q.top()<<endl;
			ans[q.top()]++;
			q.pop();
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
