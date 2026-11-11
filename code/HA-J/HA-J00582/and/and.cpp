#include<bits/stdc++.h> 
using namespace std;
int m,n;
long long a[200005],maxx=-99999;
void dfs(long long x,long long y,long long z){
	if(x==0){
		maxx=max(maxx,z);
		return ;
	}
	for(int i=y;i<=n;i++){
		int t=z;
		if(x==m)z=a[i];
		else z=(z&a[i]);
		dfs(x-1,i+1,z);
		z=t;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(m,1,0);
	cout<<maxx;
	return 0;
}

