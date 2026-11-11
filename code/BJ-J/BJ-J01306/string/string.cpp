#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	long long l=1,r=n,l1=a[1],r1=a[n],num=0;
	while(l<=r)
	{
		if(l>=r)
		{
			break;
		}

		if(b[l]!=b[r])
		{
			num++;
		}
		l1--;
		r1--;				
		if(l1==0)
		{
			l++;
			l1=a[l];
		}
		if(r1==0)
		{
			r--;
			r1=a[r];
		}

	}
	cout<<num;
	return 0;
}
