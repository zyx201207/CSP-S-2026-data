#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,ans,i,j;
string s;
//struct node
//{
//	ll k;
//	char s;
//}a[N],b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
//		cin>>a[i].k>>a[i].s;
//		b[n-i+1].k=a[i].k;
//		b[n-i+1].s=a[i].s;
		int k;
		char a;
		cin>>k>>a;
		for(int i=1;i<=k;i++)
		{
			s+=a;
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
//	while(i<=n && j<=n)
//	{
//		if(a[i].k==0) i++;
//		if(b[j].k==0) j++;
//		if(a[i].s!=a[j].s && a[i].k>0 && b[j].k>0)
//		{
//			ans++;
//			a[i].k--;
//			b[j].k--;
//		}
//		else if (a[i].s==a[j].s && a[i].k>0 && b[j].k>0)
//		{
//			i++;
//			j++;
//			a[i].k--;
//			b[j].k--;
//		}
//	}
	cout<<ans/2;
	return 0;
}
