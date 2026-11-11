#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],s[N];
int n,m,ans;
bool cmp(int a,int b)
{
	return a>b;
}
bool check(int mid,int plc)
{
	int num=mid-plc;
	if(a[plc]*num-s[mid]+s[plc]<=m)return 1;
	else return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<n;i++)
	{
		int l=i+1,r=n;
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(check(mid,i))l=mid;
			else r=mid-1;
		}
		ans=max(l-i+1,ans);
	}
	cout<<ans<<endl;
	return 0;
}
//请输入文本 
//15：27写完T1，祝下次我不会再饭堂（二分好难调啊） 
