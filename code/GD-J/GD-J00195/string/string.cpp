#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll n;
ll a[N];
char c[N];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	ll g1=1,g2=n;//g1表示前边滚动，g2表示后边滚动
	while(g1!=g2)
	{
		while(a[g1]>=a[g2]&&g2>g1)
		{
			if(c[g1]!=c[g2])ans+=a[g2];
			a[g1]-=a[g2];
			g2--;
		}
		while(a[g1]<=a[g2]&&g1<g2)
		{
			if(c[g1]!=c[g2])ans+=a[g1];
			a[g2]-=a[g1];
			g1++;
		}
	}
	cout<<ans;
	return 0;
}

