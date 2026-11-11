#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,m;
long long haha()
{
    long long b,c;
    cin >> b;
    long long ee=b;
	for(int i=2; i <= n;i++)
	{
		cin >> c;
		ee=ee&c;
	}
	return ee;
}
long long tp1()
{
	cin >> a[1];
	long long maxn=a[1];
    for(int i=2; i <= n; i++)
    {
    	cin >> a[i];
    	maxn=max(maxn,a[i]);
	}
	return maxn;
}
long long tp2()
{
	cin >> a[1];
	int pos;
	long long minn=a[1];
    for(int i=2; i <= n; i++)
    {
    	cin >> a[i];
    	minn=min(minn,a[i]);
    	pos=i;
	}
	long long ans=a[pos-1];
	for(int i=1; i <= n; i++)
	{
		if(a[i]!=minn&&i!=pos-1)
		{
			ans=ans&a[i];
		}
	}
	return ans;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n >>m;
    long long ans=1;
    if(n==m)
    {
    	cout << haha();
    	return 0;
	}
	if(m==1)
	{
		cout << tp1();
		return 0;
	}
	if(m=n-1)
	{
		cout << tp2();
		return 0;
	}
	
	for(int i=1; i <= n ; i++)
	{
		cin >> a[i];
	}
	


    return 0;
}
