#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 5;
struct T
{
	ll num;
	char ch;	
}a[N];
ll n,l,r,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].ch;
	l=1,r=n;
	while(l<r)
	{
		if(a[l].num>a[r].num)
		{
			a[l].num-=a[r].num;
			ans+=a[r].num*(a[l].ch!=a[r].ch);
			r--;
		}
		else if(a[l].num<a[r].num)
		{
			a[r].num-=a[l].num;
			ans+=a[l].num*(a[l].ch!=a[r].ch);
			l++;
		}
		else
		{
			ans+=a[l].num*(a[l].ch!=a[r].ch);
			l++,r--;
		} 
	}
	cout<<ans;
	return 0;
}
