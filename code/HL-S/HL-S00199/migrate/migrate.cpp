#include<bits/stdc++.h>
using namespace std;
void solve()
{
	long long a[100009];
	long long n,m,cnt=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i+3;j<=n&&abs(a[j]-a[i])<=m*2&&j<=i+3;j++)
		{
			bool flag=1;
			for(long long k=i+1;k<=j;k++)
			{
				if(a[k]-a[k-1]>m) 
				{
					flag=0;
					break;
				}
			}
			if(a[j]-a[i+1]<m||a[j-1]-a[i]<m) flag=0;
			if(flag)
			{
				cnt++;
				cout<<i<<' '<<j<<endl;
			}
		//	else cout<<"NO"<<endl;
		}
	}
	cout<<cnt;
} 
int main()
{
	long long R,Q;
	cin>>R>>Q;
	while(Q--) solve();
	return 0;
}
