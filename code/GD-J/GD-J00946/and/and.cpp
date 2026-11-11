#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long M=(1<<30)-1;
int n,m,a[N],ans;
void dp(int x,int num,int cnt)
{
	if(cnt<=ans)return;
	if(x>n||num>=m)
	{
		if(cnt!=M&&num==m)ans=max(cnt,ans);
		return;
	}
	dp(x+1,num+1,(cnt&a[x]));
	dp(x+1,num,cnt);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp(1,0,M);
	cout<<ans;
	return 0;
} 
