#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,ans;
int a[N];
struct node
{
	int x;
	string y;
}cnt[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>a[i]>>s;
		cnt[i].x=a[i];
		cnt[i].y=s;
	}
	for(int i=1,j=n;i<j;)
	{
		if(cnt[i].x>=cnt[j].x)
		{
			if(cnt[i].y==cnt[j].y)
			{
				cnt[i].x-=cnt[j].x;
				j--;
				continue;
			}
			else
			{
				ans+=cnt[j].x;
				cnt[i].x-=cnt[j].x;
				j--;
				continue;
			}
		}
		if(cnt[i].x<=cnt[j].x)
		{
			if(cnt[i].y==cnt[j].y)
			{
				cnt[j].x-=cnt[i].x;
				i++;
				continue;
			}
			else
			{
				ans+=cnt[i].x;
				cnt[j].x-=cnt[i].x;
				i++;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
