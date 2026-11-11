#include<bits/stdc++.h>
using namespace std;
const int MAXN=200010;
int n;
long long ans=0;
struct Node
{
	long long cnt;
	char c;
}a[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i].cnt;
		cin>>a[i].c;
	}
	int i=n-1,j=0; 
	while (i>=0&&j<i)
	{
		if (a[i].c==a[j].c)
		{
			if (a[i].cnt>=a[j].cnt)
			{
				a[i].cnt-=a[j].cnt;
				j++;
			}
			else
			{
				a[j].cnt-=a[i].cnt;
				i--;
			}
		}
		else
		{
			if (a[i].cnt>=a[j].cnt)
			{
				ans+=a[j].cnt;
				a[i].cnt-=a[j].cnt;
				j++;
			}
			else
			{
				ans+=a[i].cnt;
				a[j].cnt-=a[i].cnt;
				i--;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
