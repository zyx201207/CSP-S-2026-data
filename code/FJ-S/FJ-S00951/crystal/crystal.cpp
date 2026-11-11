#include<bits/stdc++.h>
using namespace std;

const int N=5*1E5;
long long int a[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==0)
	{
		int od=a[1],maxx=0,ans=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==od) ans++;
			else
			{
				if(ans>=maxx) maxx=ans;
				ans=1;
				od=a[i];
			}
		}
		cout<<maxx<<endl;
		return 0;
	} 
	else
	{
		int j=0;
		for(int i=1;(i+1)*i/2<=m;i++) j++; 
		if(m==2)
		{
			if((n+1)*n/2<m)
			{
				cout<<n-1;
			}
			else
			{
				cout<<2;
			}
		}
		else
		{
			if((n+1)*n/2<m)
			{
				if((m-(n)*(n-1)/2)%n==0) cout<<n;
				else cout<<n-1;
			}
			else
			{
				cout<<(m*2/j)*1<<endl;
			}
		}
		return 0;
	}
}
