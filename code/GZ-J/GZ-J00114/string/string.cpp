//GZ-J00114 ÍõÕıÅí 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>c[i];
	ll ans=0,l=1,r=n;
	while(l<r)
	{
		if(l==r)
		break;
		if(c[l]==c[r])
		{
			if(a[l]>a[r])
				a[l]-=a[r],r--;
			else if(a[l]<a[r])
				a[r]-=a[l],l++;
			else
				l++,r--;
		}
		else
		{
			if(a[l]>a[r])
				ans+=a[r],a[l]-=a[r],r--;
			else if(a[l]<a[r])
				ans+=a[l],a[r]-=a[l],l++;
			else
				ans+=a[l],l++,r--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
