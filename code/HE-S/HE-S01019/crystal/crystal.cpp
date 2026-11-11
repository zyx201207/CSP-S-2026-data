#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int a[N],n,cnt;
ll m,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int p=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		sum+=1ll*(i-p-1)*(a[i]-a[i-1]);
		while(sum>m)
		{
			p++;
			sum-=a[i]-a[p];
		}
		ans=max(ans,i-p);
	}
	cout<<ans;
}
 
