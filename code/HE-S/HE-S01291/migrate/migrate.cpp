#include<bits/stdc++.h>
using namespace std;
long long c,t,a[10000001],k,n,d,sum,b;
int main()
{ 
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		k=0;
		 b=abs(a[0]-a[1]);
		 sum=(2*d)-b;
		 sum=a[n-1]-sum;
		while(a[k]<=sum)
			{
				k++;
			}	
			cout<<k<<endl;
		}
		return 0;
}
