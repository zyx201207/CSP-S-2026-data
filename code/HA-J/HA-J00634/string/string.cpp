#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N];
char c[N];
string s=" ";
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s+=c[i];
	}
	int mid=(n+1)/2,p1=0,p2=0,ans=0;
	for(int i=1;i<mid;i++)
	{
		if(s[i]!=s[mid]) p1++;
	}
	for(int i=mid+1;i<=n;i++)
	{
		if(s[i]!=s[mid]) p2++;
	}
	if(p1==0 && p2==0)
	{
		cout<<"0";
		return 0;
	}
	if(p1>p2)
	{
		for(int i=1;i<mid;i++) ans+=a[i];
	}
	else if(p2>p1)
	{
		for(int i=mid+1;i<=n;i++) ans+=a[i];
	}
	else
	{
		int ans1=0,ans2=0;
		for(int i=1;i<mid;i++) ans1+=a[i];
		for(int i=mid+1;i<=n;i++) ans2+=a[i];
		ans=max(ans1,ans2);
	}
	cout<<ans;
	//cout<<"1";
	return 0;
}

