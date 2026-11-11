#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s1;
ll l,r,ans;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++) s1+=c;
	}
//	cout<<s1<<'\n';
	r=s1.size()-1;
	while(l<=r)
	{
		if(s1[l]!=s1[r])
		{
			ans++;
//			cout<<s1[l]<<' '<<s1[r]<<'\n';
		}
		l++,r--;
//		cout<<"l="<<l<<" r="<<r<<'\n';
//		cout<<s1[l]<<' '<<s1[r]<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
