
#include<bits/stdc++.h>
using namespace std;
long long n,l,r,s;
struct node
{
	long long x;
	char y;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	r=n-1;
	while (l<=r)
	{
		if (a[l].y!=a[r].y)
		{
			s+=min(a[l].x,a[r].x);
		}
		l++;
		r--;
	}
	cout<<s;
	return 0;
}
