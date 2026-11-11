#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long dp[500005];
long long a[500005];
int main(int argc, char** argv) {
	
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	freopen("crystal2.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=5)
	bool A=1,B=1;
	for(int i=1;i<=n;i++)
	{
		A=A&&(a[i]==i);
	}
	if(A)
	{
		int ans=1,i=1;
		while(m-i>=0)
		{
			m-=i;
			i++;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=2;i<n;i++)
	{
		B=B&&(a[i-1]-a[i]==a[i]-a[i+1]);
	}
	if(B)
	{
		int ans=1,i=1,ccc=abs(a[2]-a[1]);
		while(m-i*ccc>=0)
		{
			m-=i*ccc;
			i++;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		dp[i]=abs(a[i]-a[i-1]);
	}
	//sort(dp+2,dp+1+n);
	long long int ans=1,i=dp[2],j=2;
	while(m-i>=0)
	{
		m-=i;
		i+=dp[++j];
		ans++;
		//cout<<m<<endl;
		//youmeiyouwanflorrde
	}
	cout<<ans;
	//2578tps
	/*
	bool A=1,B=1;
	for(int i=1;i<=n;i++)
	{
		A=A&&(a[i]==i);
	}
	if(A)
	{
		int ans=1,i=1;
		while(m-i>=0)
		{
			m-=i;
			i++;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=2;i<n;i++)
	{
		B=B&&(a[i-1]-a[i]==a[i]-a[i+1]);
	}
	if(B)
	{
		int ans=1,i=1,ccc=abs(a[2]-a[1]);
		while(m-i*ccc>=0)
		{
			m-=i*ccc;
			i++;
			ans++;
		}
		cout<<ans;
	}*/
	return 0;
}
