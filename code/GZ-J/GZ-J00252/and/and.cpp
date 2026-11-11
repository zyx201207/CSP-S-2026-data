//GZ-J00252 贵阳市第十七中学 吴芸智
#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
int a[N],b[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1,j=n;i<=n,j>=1;i++,j--)
    {
    	b[i]=a[j];
	}
	int ans=b[1]&b[2];
	for(int i=3;i<=m;i++)
	{
		ans=ans&b[i];
	}
	cout<<ans;
	return 0;
}
