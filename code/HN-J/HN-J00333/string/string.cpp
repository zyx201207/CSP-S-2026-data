#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
const int N=2e5+5;
long long a[N];
char b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		int minn=min(a[l],a[r]);
		a[l]-=minn,a[r]-=minn;
		if(b[l]!=b[r]) cnt+=minn;
		if(a[l]==0) l++;
		else r--;
	}
	cout<<cnt;
}
