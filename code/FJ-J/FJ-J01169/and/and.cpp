#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
long long e[40];
int main()
{
	freopen("ans.in","r",stdin);
	freopen("and.out","w",stdout);
	long long abcd=1;
	for(int i=0;i<=35;i++)
	{
		e[i]=abcd;
		abcd*=2;
	}
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int sum=1;
	
	if(n==1) 
	{
		cout<<a[1];
		return 0;
	}
	for(int i=n;i>=1,m>=1;i--,m--)
	{
		int ans=0;
		if(i==n) 
		{
			sum=a[i];
			continue;
		}
		int j=0;
		while(a[i]!=0 && sum!=0)
		{
			int x=a[i]%2,y=sum%2;
			if(x==y && x==1) ans+=e[j];
			a[i]/=2;
			sum/=2;
			j++;
		}
		sum=ans;
		cout<<sum<<" ";
	}
	cout<<sum;
	return 0;	
} 
