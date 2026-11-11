#include<bits/stdc++.h>
using namespace std;
long long a[300000],n,m,res=-1;

bool cmp(long long x,long long y){return x>y;}
void dfs(long long x,long long y,long long cnt){
	if(x==n&&y==m){
		res=max(res,cnt);
			
		return;
	}
	if(n-x<m-y)return;
	if(y>=m||x>=n)return;
	dfs(x+1,y+1,cnt&a[x+1]);
	dfs(x+1,y,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,(1<<30)-1);
	cout<<res;
	return 0;
} 
