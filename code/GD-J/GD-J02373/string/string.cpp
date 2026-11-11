#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	long long minn=0;
	long long l=1,r=n;
	long long left=a[1],right=a[n];
	while(l<=r)
	{
		if(c[l]!=c[r])
		{
			if(left>right) minn+=right;
			else if(left<right) minn+=left;
			else minn+=left;
		}
		if(left>right)
		{
			left-=right;
			r--;
			right=a[r];
		}
		else if(left<right)
		{
			right-=left;
			l++;;
			left=a[l];
		}
		else
		{
			l++;
			r--;
			right=a[r];
			left=a[l];
		}
	}
	cout<<minn<<endl;
	return 0;
}
