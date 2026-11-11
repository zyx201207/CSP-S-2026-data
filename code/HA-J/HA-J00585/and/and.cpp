#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200009];
int ans=0,num=0;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;int mm=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num^=a[i];
		if(ans^a[i]>ans&&m!=0)
		{
			m--;
			ans^=a[i];
		}
		if(m==0)break;
	}
	if(mm==n)
	{
		cout<<num<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}
