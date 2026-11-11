#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],s[500001];
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+i*(a[i]-a[i-1]);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' '<<s[i]<<endl;
	cout<<endl;
	for(int r=1,l=1;r<=n;r++)
	{
		while(s[r]-s[l]-l*a[r]+l*a[l]>m)
			l++;
		ans=max(ans,r-l+1);			
	}
	cout<<ans;
	
	return 0;
}
//0 0 0 1 2 3 4 5 0 0
//0 0 0 4 5 6 7 8 0 0





