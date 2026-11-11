#include<bits/stdc++.h>
using namespace std;
#define xll __int128
#define ll long long
const int N=5e5+10;
ll a[N];
xll s[N];
//void print(xll x)
//{
//	string s;
//	while(x) s.push_back((int)(x%10)+'0');
//	reverse(s.begin(),s.end());
//	cerr<<s<<"\n";
//}
int n;
ll m;
int find(int x)
{
	int l=1,r=x,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[x]*(xll)(x-mid+1)<=m+s[x]-s[mid-1]) r=mid-1,ans=mid;
		else l=mid+1;
	}
	return x-ans+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
//	cout<<"-------------\n";
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
//	cout<<(s[n]<0)<<"\n";
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,find(i));
	cout<<ans;
	return 0;
}
