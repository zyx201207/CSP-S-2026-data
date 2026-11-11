#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
		if(pow(2,m)-1==a[i]) 
		{
			cout<<a[i];
			break;
		}
		if(b[a[i]]==m) 
		{
			cout<<a[i];
			break;
		}
	}
	return 0;
}
