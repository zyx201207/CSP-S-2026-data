#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],s[500005],l,r,x,y,mid,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	l=1;
	for(int i=2;i<=n;i++)
	{
		x=x+(a[i]-a[i-1])*(i-l);
		while(x>m)
		{
			x=x-(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

