#include<bits/stdc++.h>
using namespace std;
//关注luogu 1406766 谢谢喵 
const int N=505,M=5e5+5;
const long long INF=1e18;
int C,n,m,d,q,w[M];
long long a[N][N];
struct node{
	int x,y;
};
vector<node> z[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		while(t--){
			int x,y;
			cin>>x>>y;
			z[x].push_back(node{i,y});
		}
	}
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++){
		for(int j=0;j<z[i].size();j++){
			for(int k=j+1;k<z[i].size();k++){
				node t=z[i][j],t2=z[i][k];
				a[t2.x][t.x]=a[t.x][t2.x]=min(a[t.x][t2.x],1ll*(t.y+t2.y));
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)a[i][j]=0;
				else a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=INF;
		for(node i:z[x]){
			for(node j:z[y]){
				ans=min(ans,a[i.x][j.x]+1ll*i.y+1ll*j.y);
			}
		}
		cout<<ans+1ll*w[x]+1ll*w[y]<<"\n";
	}
	return 0;
}
/*
测试点1-8显然可以暴力 32pts
9-11 好像直接预处理也可做 - 12pts
20-21 只有两条铁路           -8pts
得了超过一半的分？
22,23 d<=2 

哎不对好像可以把铁路看做点，站看做边
每次枚举第一条铁路和最后一条边 

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

场切S组T2，我无意是兴奋的 
*/

