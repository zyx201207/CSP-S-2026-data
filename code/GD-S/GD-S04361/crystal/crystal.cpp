#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans,maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ans = 0;
		for(int j=i;j>=1;j--)
		{
			ans += (a[i]-a[j]);
			if(ans > m)
			{
				maxx = max(maxx,(long long)i-j);
				break;
			}
			if(ans == m)
			{
				maxx = max(maxx,(long long)i-j+1);
				break;
			}
		}
	}
	cout<<maxx;
	return 0;
} 

