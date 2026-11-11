#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e6*2;
int t,n;
ll d,x[N];
ll sum[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		int cnt=n;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			sum[i]=sum[i-1]+(x[i]-x[i-1]);
			if(x[i]-x[i-1]>d)
			{
				cnt--;
			}
		}
		if(cnt/2>d)
		{
			if(cnt%2==1)
			{
				cout<<2;
			}
			else
			{
				cout<<1;
			}
		}
		else
		{
			cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
