#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
using namespace std;
const int N=2e5+10;
ll a[N];
char c[N];
ll ans;

int main()
{
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1;
	int r=n;
	while(l!=r)
	{
		if(l>r)
			break;
		if(c[l]!=c[r])
			ans+=min(a[l],a[r]);
		if(a[l]>a[r])
		{
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
		else if(a[l]<a[r])
		{
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
		else
		{
			a[l]=0;
			a[r]=0;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
