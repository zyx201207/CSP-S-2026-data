#include<bits/stdc++.h>
using namespace std;
char c[200005];
int a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	long long cnt=0;
	for(int l=1,r=n;l<r;)
	{
		int al=a[l],ar=a[r];
		char cl=c[l],cr=c[r];
		if(al<ar)
		{
			cnt+=al;
			a[r]-=a[l];
			l++;
		}
		if(al>ar)
		{
			cnt+=ar;
			a[l]-=a[r];
			r--;
		}
		if(al==ar)
		{
			cnt+=al;
			l++;r--;
		}
		if(cl==cr)
			cnt-=min(ar,al);
	}
	cout<<cnt;
	return 0;
}
