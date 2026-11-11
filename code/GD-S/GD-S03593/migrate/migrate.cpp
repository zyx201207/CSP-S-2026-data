#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long x[N];
long long f[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
//		memset(f,0,sizeof(f));
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int cnt=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1+cnt;j<=n;j++)
			{
				
				if(x[j]-x[i]>d) break;
				cnt++;
			}
			f[i]=cnt;
			cnt--;
		}
		f[n]=1;
		for(int i=1;i<=n;i++) cout<<f[i]<<" ";
		cout<<endl;
	    int ans=0;
	    int ok1=0,ok2=1;
		for(long long i=1;i<=n-3;i++)
		{
			for(long long j=i+3;j<=n;j++)
			{
				for(long long ii=1;ii<n;ii++)
				{
					int aa=min(f[ii],n-ii),bb=min(f[ii+1],n-ii-1),cc=min(f[ii-1],n-ii+1); 
					if(aa==bb&&ok1==0&&aa!=1)
					{
						ok1=ii;
					}
					else if(aa==bb&&ok1!=0&&aa!=1) 
					{
						ok1=0;
						break;
					}
					else if(aa==1||ok1==ii) ok2=1;
					else if(aa!=1) 
					{
						ok2=0;
						break;
					}
					else if(aa==0)
					{
						ok2=0;
						break;	
					}
				}
				if(ok1&&ok2) 
				{
//					cout<<"&"<<i<<" "<<j<<endl;
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
