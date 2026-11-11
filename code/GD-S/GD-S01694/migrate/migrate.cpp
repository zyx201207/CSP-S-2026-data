#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int n,d,a[N],b[N];
int main()
{
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=2;i<=n;i++)
		{
			if(d<abs(a[i]-a[i-1]))
			{
				sum++;
			}
		}
		if(sum==(n-1)) cout<<"0\n";
		if(((a[2]-a[1])==(a[3]-a[2]))&&((a[4]-a[3])==(a[5]-a[4]))&&((a[6]-a[5])==(a[7]-a[6]))) 
		{
			if(d<2*abs(a[2]-a[1])&&d>=abs(a[2]-a[1])) cout<<"0\n";
			else if(d==2*abs(a[2]-a[1])) cout<<"1\n";
			else cout<<"0\n";
		}
		else cout<<"0\n";
	}
	return 0;
} 
