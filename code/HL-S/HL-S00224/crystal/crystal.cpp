#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=5e5+5;
ll a[MAXN],cha[MAXN];
ll n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5000)
	{
		sort(a+1,a+n+1);
		ll cnt=0;
		for(int i=1;i<=n;i++)
		{
			ll mm=m;
			ll cnt1=0,cnt2=0;
			for(int j=1;j<=i;j++)
			{
				int x=a[i]-a[j];
				if(mm>=x)
					mm-=x,cnt1++;
			}
			mm=m;
			for(int j=i+1;j<=n;j++)
			{
				int x=a[n]-a[j];
				if(mm>=x)
					mm-=x,cnt2++;
					
			}
			cnt=max(cnt,max(cnt1,cnt2));
		}
		cout<<cnt;
		return 0;
	}
	int mid=(1+n)>>1;
	for(int i=1;i<=n;i++)
		cha[i]=a[mid]-a[i];
	sort(cha+1,cha+n+1);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(cha[i]<0)
			continue;
		if(m>=cha[i]&&cha[i]>=0)
			m-=cha[i],ans++;
		else
			break;
	}
	cout<<ans;
    return 0;
}
