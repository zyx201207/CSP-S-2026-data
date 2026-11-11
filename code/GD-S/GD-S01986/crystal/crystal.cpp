#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],c[N],n,m,ans,l,r,sum,now;
bool cmp(ll a,ll b){return a<b;}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++) c[i]=a[i]-a[i-1];
	ans=sum=l=r=1;
	while(l<=r&&r<=n)
	{
		now+=(sum*c[++r]);
		sum++;
		while(now>m)
		{
			now-=(a[r]-a[++l]);
			sum--;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
