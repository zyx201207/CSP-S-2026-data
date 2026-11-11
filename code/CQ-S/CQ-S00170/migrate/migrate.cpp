#include<bits/stdc++.h>
using namespace std;
long long dp[2110101][6],c,t,n,d,x[2110101],ans;
long long nxt[2110101];
int main()
{
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d; 
		long long it=n;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
	    for(int i=n-1;i>=1;i--){
	    	while(x[i]+d<x[it])
	    	it--;
	    	nxt[i]=it;
		}
		dp[n][1]=0;
		dp[n][2]=0;
		dp[n][3]=0;
		for(long long i=n-1;i>=1;i--){
			if(nxt[i-1]<nxt[i])
			    dp[i][3]=dp[nxt[i]][3]+max(0ll,(nxt[i]-max(nxt[i-1],i)));
		    else
		    	dp[i][3]=dp[nxt[i]][4];
		    if(nxt[i-1]<nxt[i]-1)
		    	dp[i][2]=dp[nxt[i]][1];
			else if(nxt[i-1]<nxt[i])
			    dp[i][2]=dp[nxt[i]][2];
		    else
		    	dp[i][2]=dp[nxt[i]][4];
		    if(i!=1)
		    {
		        if(nxt[i]==nxt[i-1]&&nxt[i-1]==nxt[i-2])
		        dp[i][1]=dp[nxt[i]][4];
		        else if(nxt[i]==nxt[i-1]&&nxt[i-1]!=nxt[i-2])
		        dp[i][1]=dp[nxt[i]][3]+max(0ll,(nxt[i-1]-max(nxt[i-2],i)));
		        else if(nxt[i]!=nxt[i-1]&&nxt[i-1]==nxt[i-2]&&nxt[i-1]<nxt[i]-1)
		        dp[i][1]=dp[nxt[i]][1]+max(0ll,(nxt[i-1]-max(nxt[i-2],i)));
		        else if(nxt[i]!=nxt[i-1]&&nxt[i-1]==nxt[i-2])
		        dp[i][1]=dp[nxt[i]][2];
		        else
		        dp[i][1]=dp[nxt[i]][1]+max(0ll,(nxt[i-1]-max(nxt[i-2],i)));
		    }
		    if(nxt[i]==i)
			 {
			 	dp[i][1]=0;
		dp[i][2]=0;
		dp[i][3]=0;
			 }
		}
		for(int i=1;i<n;i++)
		{
			ans+=dp[nxt[i]][1];
		}
		cout<<ans<<endl;
	}
} 
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
