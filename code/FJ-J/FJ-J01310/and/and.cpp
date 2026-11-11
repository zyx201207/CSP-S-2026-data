#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
void solve1(){
	int ans=a[1]&a[2];
	for(int i=3;i<=n;i++)
		ans=ans&a[i];
	cout<<ans;
}
void solve2(){
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
}
void solve3(){
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int temp;
		if(i<=n-5)
		{
			temp=a[i+1]&a[i+2];
			for(int j=1;j<=n;j++)
			{
				if(i!=j&&j!=i+1&&j!=i+2)
				temp=temp&a[j];
			}
		}	
		else 
		{
			temp=a[i-1]&a[i-2];
			for(int j=1;j<=n;j++)
			{
				if(i!=j&&j!=i-1&&j!=i-2)
				temp=temp&a[j];
			}
		}
		ans=max(ans,temp);
	}
	cout<<ans;
}
void solve()
{
	int ans=a[n]&a[n-1];
	for(int i=n-2;i>=n-m;i--)
	{
		ans=ans&a[i];
	}
	cout<<ans; 
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==m) solve1();
	else if(m==1) cout<<a[n]; 
	else if(m==2) solve2();
	if(m==n-1) solve3();
	else solve();
	return 0;
}
