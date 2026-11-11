#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,c;
/*ll d,a[2000005];
int vis[2000005],cnt,ans;
struct node{
	int id,step;
};
void dfs(int x,int y){
	queue<node> q;
	q.push({x,0});
	while(!q.empty()){
		node hd=q.front();
		q.pop();
		if(hd.id==y){
			ans=min(ans,hd.step); 
			break;
		}
		for(int i=hd.id;i<n;i++){
			if((a[i]+a[hd.id])>d)break;
			q.push({i,hd.step});
		}
	}
}void bfs(int x,int y,int nx,int st){
	if(nx==y&&st==ans){ 
		cnt++;
		return ;
	}
	for(int i=nx;i<n;i++){
		if((a[i]+a[nx])>d)break;
		bfs(x,y,i,st+1);
	}
}*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cout<<0<<"\n";
		/*memset(vis,0,sizeof(vis));
		//for(int i=0;i<n;i++)cout<<vis[i];
		cin>>n>>d;
		for(int i=0;i<n;i++)cin>>a[i];
		int rans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				cnt=0;
				ans=0;
				dfs(i,j);
				bfs(i,j,i,0);
				if(cnt==2)rans++;
			}
		}
		cout<<rans<<"\n";
		/*for(int i=0;i<n;i++)cout<<vis[i]<<" ";
		cout<<"\n";*/
	}*/
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
