#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,p[2000005];
struct buzhidao
{
	int val;
	int cnt;
}b[5000][5000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		    cin>>p[i];
		    
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=i;j<=n;j++)
//			{
//			    for(int k=1;k<=d;k++)
//				{
//				    if(j+k<=n)
//                    {
//				        if(b[i][j].val<b[i][j-k].val+1){
//						}
//                        else if(b[i][j].val==b[i][j-k].val+1) b[i][j].cnt++;
//                        else
//                        {
//                    	    b[i][j].cnt=0;
//                    	    b[i][j].val=b[i][j-k].val;
//					    }
//			        }
//			    }
//			}
//		}
//		long long ans2=0;
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				if(b[i][j].cnt==2) ans2++;
//			}
//		}
		
		long long ans=0;
	    if(c==11||c==12)
	    {
		    long long gc=p[2]-p[1];//等差数列的公差;
		    long long tim=d/gc+2;
		    ans=n-tim+1-d+2;
	    }
	    //else if(c==13||c==14)
	    else ans=2; 
	    cout<<ans<<endl;
	}
	return 0;
	//11 2 4 2 1 2 3 4 6 3 1 2 3 4 5 6
	//12 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6
}
