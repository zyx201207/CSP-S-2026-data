#include<bits/stdc++.h>
using namespace std;
long long INF=2*1e5+5;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[INF],ans=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if(m==2)
	{
		cout<<(a[n]&a[n-1]);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	ans=a[n];
//	if(m==1)
//	{
//		cout<<ans;
//		fclose(stdin);
//		fclose(stdout);
//		return 0;
//	}
//	else if(m==2)
//	{
//		cout<<(ans&a[n-1]); 
//		fclose(stdin);
//		fclose(stdout);
//		return 0;
//	}
	long long i=n;
	m-=1;
	while(m>0)
	{
		i--;
		m--;
		ans=(ans&a[i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
3 15 12 12


5 3
31 3 1 15 7
*/ 
