#include<bits/stdc++.h>
using namespace std;
long long a[500001];
long long ans[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	ans[1]=1;
	long long num=0,l=1;
	for(int i=2;i<=n;i++)
	{
		if(num+(i-l)*(a[i]-a[i-1])<=m)
		{
			num+=(i-l)*(a[i]-a[i-1]);
			ans[i]=ans[i-1]+1;
		}
		else
		{
			ans[i]=ans[i-1]+1;
			num+=(i-l)*(a[i]-a[i-1]);
			while(num>m){
				num-=(a[i]-a[l]);
				l++;
				ans[i]--;
			}
		}
	}
	long long maxx=-1;
	for(int i=1;i<=n;i++){
		maxx=max(ans[i],maxx);
	}
	cout<<maxx;
	return 0;
}
