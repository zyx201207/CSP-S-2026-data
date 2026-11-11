#include<bits/stdc++.h>
using namespace std;
int n,l=1,r;
const int N=2*1e5;
long long a[N+10],ans;
char c[N+10];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	while(1)
	{
		if(l==r)
		  break;
		if(a[l]>a[r])
		{
		    a[l]-=a[r];
			if(c[r]!=c[l])
			  ans+=a[r];
			r--;
		}
		else if(a[l]<a[r])
		{
			a[r]-=a[l];
			if(c[r]!=c[l])
			  ans+=a[l];
			l++;
		}
		else
		{
			if(c[r]!=c[l])
			  ans+=a[r];
			r--;
			l++;
		}
	}
	cout<<ans;
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
