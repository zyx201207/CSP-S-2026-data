#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],mid,ans;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	mid=n/2+1;
	sort(a+1,a+n+1);
	for(int i=mid-1;i>=1;i--)
	{
		while(a[i]!=a[mid])
		{
			a[i]++;
			m--;
			if(m==0) break;
		}
	}	
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[mid])
		ans++;
	}
	cout<<ans;
	return 0;
}
