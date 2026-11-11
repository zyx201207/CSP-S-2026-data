#include<bits/stdc++.h>
using namespace std;
long long a[500101];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,l=1,c=0;
	long long m,h=0;
	cin>>n>>m;
	for(int i1=1;i1<=n;i1++)
		cin>>a[i1];
	sort(a+1,a+n+1);
	for(int i1=1;i1<=n;i1++)
	{
		h+=(i1-l)*(a[i1]-a[i1-1]);
		while(h>m)
			h-=a[i1]-a[l++];
		c=max(c,(i1-l+1));
	}
	cout<<c;
	return 0;
}
