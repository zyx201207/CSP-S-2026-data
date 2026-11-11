#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans=1,l=1,tmp;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n&&l<=i;i++)
	{
		while((a[i]-a[i-1])*(i-l)>m&&l<i)
		{
			m+=a[i-1]-a[l]; l++; tmp--;
		}
		if((a[i]-a[i-1])*(i-l)>m) break;
		m-=(a[i]-a[i-1])*(i-l); tmp++; ans=max(tmp,ans);
	}
	cout<<ans;
	return 0;
} 
