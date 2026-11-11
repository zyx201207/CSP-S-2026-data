#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
int n;
struct afo
{
	long long y;
	char z;
} a[200005];
long long l=1;
long long r=0;
void check(string a)
{
	while(l<=r)
	{
		if(a[l-1]!=a[r-1])
		{
			cnt++;
		}
		l++;r--;
	}
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string ans="";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].y>>a[i].z;
		r+=a[i].y;
		for(int j=1;j<=a[i].y;j++)
		{
			ans+=a[i].z;
		}
	}
	check(ans);
	cout<<cnt;
	return 0;;
}
