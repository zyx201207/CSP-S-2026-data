#include<bits/stdc++.h>
using namespace std;
long long n,m,num;
long long a[200000000];//200000000
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//n=5*pow(10,5);
	//m=pow(10,18);
	//cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++) cin>>a[i];
	//for(int i=1;i<=n;i++) a[i]=pow(10,12);
	sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	for(long long i=1;i<=n;i++)
	{
		long long sum=0;
		for(long long j=1;j<=i;j++)
		{
			sum+=a[i]-a[j];
		}
		if(sum<=m) num=i;
		else break;
	}
	cout<<num;
}
