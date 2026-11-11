#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,sum,num,f[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i];
		f[i]=a[i]+f[i-1];
	}
	for(int i=1;i<=n;i++)
		if(sum>=f[i])
			num=i;
	if(n==1)
		cout<<0;
	else
		cout<<(sum+1)/2;
	return 0;
}
