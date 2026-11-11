#include <bits/stdc++.h>

using namespace std;
struct node
{
	long long num;
	char c;
};
const int N = 2e5+5;
long long ans = 0;
int n;
node a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i].num;
		cin>>a[i].c;
	}
	int l = 1,r = n;
	while(1)
	{
		if(l==r)
		{
			cout<<ans;
			return 0;
		}
		if(a[l].c==a[r].c)
		{
			long long mi = min(a[l].num,a[r].num);
			if(a[l].num==mi)
			{
				l++;
				a[r].num-=mi;
			}
			else
			{
				a[l].num-=mi;
				r--;
			}
		}
		else
		{
			long long mi = min(a[l].num,a[r].num);
			if(a[l].num==mi)
			{
				l++;
				a[r].num-=mi;
				ans+=mi;
			}
			else
			{
				a[l].num-=mi;
				r--;
				ans+=mi;
			}
		}
		if(a[r].num==0) r--;
	}
	return 0;
}