#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,flag;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int k=a[i];
		while(k>2&&k%2==0)
			k/=2;
		if(k!=2)
			flag=1;
	}
		
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--)
		ans&=a[i];
	if(flag==0)
		cout<<a[n-m+1];
	else
		cout<<ans;
	return 0;
}
