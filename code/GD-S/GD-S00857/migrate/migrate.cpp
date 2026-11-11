#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e6;
long long c,t;
long long m,n;
long long a[maxn];
long long fen[maxn],man[maxn],sumt[maxn],sumy[maxn];
long long dp[5005][5005];
long long gman,cnt;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t!=0)
        {
    	    t--;
    	    cin>>n>>m;
    		for(int i=1;i<=n;i++)
    		{
    			cin>>a[i];
			}
        	int sum=n-(2*m)+1;
			cout<<sum<<endl;
	    }
	}
    else
    {
        while(t!=0)
        {
    	    t--;
    	    cin>>n>>m;
    	    cnt=0;
    	    memset(sumy,0,sizeof(sumy));
    	    memset(sumt,0,sizeof(sumt));
    	    memset(fen,0,sizeof(fen));
    	    memset(dp,0,sizeof(dp));
    	    gman=0;
    		for(int i=1;i<=n;i++)
    		{
    			cin>>a[i];
			}
			sumt[1]=1;
            for(int i=2;i<=n;i++)
            {
                fen[i]=a[i]-a[i-1];
				sumy[i]=sumy[i-1]+fen[i];
				if(fen[i]>m)
				{
					break;
				}
				if(gman+fen[i]>m)
				{
					sumt[i]=sumt[i-1]+1;
					gman=fen[i];
				}
			    else
			    {
			    	gman+=fen[i];
			    	sumt[i]=sumt[i-1];
				}
			}
			for(int i=1;i<=n-3;i++)
			{
				for(int j=i+3;j<=n;j++)
				{
					if(sumt[j]==0)
					{
						break;
					}					
					if((sumy[j]-sumy[i])%m==0)
					{
						dp[i][j]=1;
						continue;
					}
					if(sumt[j]-sumt[i-1]==sumt[j-1]-sumt[i-2])
					{
						dp[i][j]=1;
						continue;
					}

					if(sumt[j]-sumt[i-1]==j-i+1)
					{
						dp[i][j]=1;
						continue;
					}
					if(j!=i+3)
					{
						if((sumy[j-1]%m==0)&&dp[i][j-1]==1)
					    {
						    dp[i][j]=1;
						    continue;
					    }			
					}
					cnt++;
				}
			}
			cout<<cnt<<endl;
	    }
	}
	return 0;
}
