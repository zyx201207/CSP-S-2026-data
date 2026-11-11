#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[1000010];
bool cmp(int x,int y)
{
	if(x>y)return 1;
	if(x<y)return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	
	
	for(int i=1;i<=m;i++)
	{
		ans=(ans and a[i]);
	}
	cout<<ans;
	
	return 0;
}
