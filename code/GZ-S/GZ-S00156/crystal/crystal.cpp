//GZ-S00156 遵义市第一初级中学 张桢宇 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,s=-1,i;
	long long m,b;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int j=0;j<n;j++)
	{
		b=0;
		for(i=j+1;i<n&&b<=m;i++)
				b+=(a[i]-a[i-1])*(i-j);
		s=max(s,i-j-1);
	}
	cout<<s;
	return 0;
}
