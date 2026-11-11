#include<bits/stdc++.h>
using namespace std;
long long maxx=0,m,n,s;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1) {cout<<a[n]; return 0;}
	if(m==n)
	{
		s=a[1];
		for(int i=2;i<=n;i++)
			s=s&a[i];
		cout<<s;
     	return 0;
	}
	return 0;
}
