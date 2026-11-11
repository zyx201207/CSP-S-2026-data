#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[200010],res;
char str[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>str[i];
	for(int l=1,r=n;l<r;)
	{
		if(a[l]==a[r])
		{
			if(str[l]!=str[r])
				res+=a[l];
			l++,r--;
		}
		else if(a[l]<a[r])
		{
			if(str[l]!=str[r])
				res+=a[l];
			a[r]-=a[l++];
		}
		else
		{
			if(str[l]!=str[r])
				res+=a[r];
			a[l]-=a[r--];
		}
	}
	cout<<res;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
