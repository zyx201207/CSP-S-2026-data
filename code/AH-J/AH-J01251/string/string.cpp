#include<bits/stdc++.h>
#define iu long long
using namespace std;
iu n,cnt,sum,a[200010],pack=1;
char c[200010];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		if(i==1)
		{
			pack=a[1];
		}else{
			pack=__gcd(a[i],pack);
		}
	}
	for(int i=1;i<=n;i++)
	{
		a[i]/=pack;
		sum+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(int i=0;i<sum/2;i++)
	{
		if(s[i]!=s[sum-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt*pack;
	return 0;
}
