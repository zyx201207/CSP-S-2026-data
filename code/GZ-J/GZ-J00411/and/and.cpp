//GZ-J00411 贵阳市南明区华麟学校 张喆品 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200020];
int ma;
void dfs(int x,int y,int idx){
	if(y==m)ma=max(ma,x);
	if(y>=m)return ;
	if(idx>n)return ;
	int j=x;
	for(int i=idx;i<=n;i++){
		x=j;
		dfs(x&a[i],y+1,i+1);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(INT_MAX,0,1);
	cout<<ma; 
	return 0;
}

