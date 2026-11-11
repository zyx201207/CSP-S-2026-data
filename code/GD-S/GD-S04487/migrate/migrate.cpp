#include <bits/stdc++.h>
using namespace std;
int c=0;
int t=0;
void solve1()
{
	int n=0;
	int d=0;
	cin>>n>>d;
	int a[9];
	memset(a,0,sizeof(a));
	vector<int>b(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i) b[i-1]=a[i]-a[i-1];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			
		}
	}
	return;
}
void solve2()
{
	return;
}
void solve3()
{
	return;
}
void solve4()
{
	return;
}
void solve5()
{
	return;
}
void solve6()
{
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>t;
	if(c==1||c==2) 
	{
		while(t--) solve1();
	}
	else if(c>=3&&c<=10)
	{
		while(t--) solve2();
	}
	else if(c==11||c==12)
	{
		while(t--) solve3();
	}
	
	return 0;
} //THE END
