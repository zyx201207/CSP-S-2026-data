#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char c[200010];
long long sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		int q=min(a[l],a[r]);
		if(c[r]!=c[l]) sum+=q;
		a[l]-=q;
		a[r]-=q;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<sum;
	return 0;
}
