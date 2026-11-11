#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;
	cin>>n>>m;long long k=m;
	int cnt=1,ans=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int b=2;b<=n;b++)
	{
		cnt=1;m=k;
		for(int i=b;i<=n&&m>=0;i++)
		{
			long long x=(a[i]-a[i-1])*(i-b+1);
			if(m<x){
				break;
			}
			m-=x;cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
