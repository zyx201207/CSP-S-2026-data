#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050];
long long d[5050][5050];
long long m1=m;
long long ans;
long long maxx=INT_MIN;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	 for(int i=1;i<=n;i++)
	 {	
	 	for(int j=1;j<=n;j++)
	 	{
	 		d[i][j]=a[i]-a[j];
			//cout<<d[i][j]<<' ';
		}
		//cout<<endl;.
	}
	 for(int i=1;i<=n;i++)
	 {	
	 	m1=m;
	 	ans=0;
	 	for(int j=1;j<=n;j++)
	 	{
	 		if(m1>=0&&m1-d[i][j]>=0&&d[i][j]>=0)
	 		{
	 			m1-=d[i][j];
	 			ans++;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	
	return 0;
 } 
