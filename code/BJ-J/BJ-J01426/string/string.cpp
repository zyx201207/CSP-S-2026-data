#include <bits/stdc++.h>
using namespace std;
struct stu
{
	long long s;
	char c;
}a[210000];
int main()
{
	long long n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].s>>a[i].c;
	}
	long long l=0,r=n-1;
	while(l<r)
	{
		if(a[l].c!=a[r].c)cnt+=min(a[l].s,a[r].s);
		int z=a[l].s;
		a[l].s-=a[r].s;
		a[r].s-=z;
		if(a[l].s<=0)l++;
		if(a[r].s<=0)r--;
	}
	cout<<cnt;
	return 0;
}
