#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],f[200005],num=1,maxx;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	maxx=-1;
	f[1]=a[1];
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if(num<=m)
			{
				f[i]=max(f[i],(f[i-j]&a[j]));
				if(f[i]!=f[i-1])
					num++;
			}
	cout<<f[n];
}
