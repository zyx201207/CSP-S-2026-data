#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int dp[N][N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int m,n;
	cin>>n>>m;
	int ppp[N],minn=1<<30;
	for(int i=1;i<=n;i++) cin>>ppp[i],minn=min(minn,ppp[i]);
	
	cout<<minn;
	
}	
