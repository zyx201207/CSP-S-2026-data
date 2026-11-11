#include <bits/stdc++.h>
using namespace std;

long long n,cnt=0;
long long a[200005];
char c[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();

	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int s=0,e=n-1;
	while(s<e)
	{
		long long del=min(a[e],a[s]);
		a[e]-=del;
		a[s]-=del;
		if(c[s]!=c[e])
		{
			cnt+=del;
		}
		
		if(a[e]==0)e--;
		if(a[s]==0)s++;
	}
	cout<<cnt;
	return 0;
}
