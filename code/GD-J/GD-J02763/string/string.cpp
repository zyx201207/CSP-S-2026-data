#include <bits/stdc++.h>
using namespace std;
long long a[200005],ans,n,sum[200005],cnt1,cnt2,num1,num2;
char c[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	cnt1=1;
	cnt2=n;
	while (cnt1<cnt2)
	{
		if (!num1)
			num1=a[cnt1];
		if (!num2)
			num2=a[cnt2];
		if (c[cnt1]!=c[cnt2])
			ans+=min(num1,num2);
		if (num1>num2)
		{
			num1-=num2;
			num2=0;
			cnt2--;
		}
		else if (num1<num2)
		{
			num2-=num1;
			num1=0;
			cnt1++;
		}
		else
		{
			num1=0,num2=0;
			cnt1++,cnt2--;
		}
	}
	cout<<ans;
	return 0;
}
