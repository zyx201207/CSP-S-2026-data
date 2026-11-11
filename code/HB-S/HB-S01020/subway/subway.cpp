#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int c,n,m,d,q,x,y;
bool flag=0;
struct node{
	int sp;
	int k;
};
queue<int> q[N][N];
queue<node> v;
int w[N],k[N],a[N][N],t[N][N],ans;
bool b[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			//f(j==1)continue;
			//else q[a[i][j-1]][i].push_back(a[i][j]),q[a[i][j]][i].push_back(a[i][j-1]);
			cin>>t[i][a[i][j]];
			//if(i==1&&j==a[1][1])int h=t[i][a[i][j]];
			//else if(t[i][a[i][j]]!=h)flag=1;
			//else continue;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(flag==1){
			cout<<bfs(x,y);
		}
	}
	return 0;
}
