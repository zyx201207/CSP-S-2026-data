#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int b[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f1=true,f2=true;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>=3)
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) f2=false;
	}
	
	if(f2==true)//µÈ²îÊýÁÐ 
	{
		int c=a[2]-a[1];
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=i*c;
			if(sum>m) {
				cout<<i;
				return 0;
			}
		 } 
	}
	sort(a+1,a+n+1);
	int ans=-2e9;
	for(int i=1;i<n;i++)
	{
		long long sum=0;
		for(int j=n-i;j>=1;j--)
		{
			b[j]=a[n-i+1]-a[j];
			if(sum+b[j]>m) {ans=max(ans,n-i-j+1);break;}
			else sum+=b[j];
			if(j==1) ans=max(ans,n-i-j+2);
		}
	}
	cout<<ans;
}
