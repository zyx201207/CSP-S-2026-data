#include<bits/stdc++.h>
using namespace std;
/*
直接BFS暴力搜多源最短路 
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
cout<<1;
*/ 
const int N=1e6+5;
int C,T;
int n,d,a[N];//vis表示该点被不同路径经过的数量
struct node{
	int x,cnt;
}vis[N]; 
queue<int> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) vis[j]={-1,0};
			while(!q.empty()) q.pop();
			vis[i]={0,1};
			q.push(i);
			while(!q.empty()){
				int x=q.front();q.pop();
				int l=x-1,r=x+1,dis=vis[x].x;
				while(1<=l&&a[x]-a[l]<=d){
					if(vis[l].x==-1){
						q.push(l);
						vis[l].x=dis+1;
						vis[l].cnt++;
					}
					else if(vis[l].x==dis+1) vis[l].cnt++; 
					l--;
				} 
				while(r<=n&&a[r]-a[x]<=d){
					if(vis[r].x==-1){
						q.push(r);
						vis[r].x=dis+1;
						vis[r].cnt++;
					} 
					else if(vis[r].x==dis+1) vis[r].cnt++;
					r++;
				}
			}
		//	cout<<"start form: "<<i<<"\n";
			for(int j=1;j<=n;j++){
				if(vis[j].cnt==2) ans++;
				//cout<<vis[j].x<<' '<<vis[j].cnt<<"\n";
			}
		}
		cout<<ans/2<<"\n"; 
	}
	return 0;
}
