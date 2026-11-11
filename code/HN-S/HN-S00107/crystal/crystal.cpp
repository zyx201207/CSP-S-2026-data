#include<bits/stdc++.h>
using namespace std;
int n,m,d,ans[500005];
struct node{
	long long zhi,xiayiwei;
}a[500005];
bool cmp(node x,node y)
{
	return x.zhi<y.zhi;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].zhi;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)
	{
		a[i].xiayiwei=a[i+1].zhi-a[i].zhi;
	}
	ans[1]=1;
	if(m>=a[1].xiayiwei) ans[2]=2;
	else ans[2]=1;
	for(int i=3;i<=n;i++)
	{
		ans[i]=1;
		d=a[i-1].xiayiwei;
		int z=2;
		while(m>=d&&ans[i]+1<=i)
		{
			ans[i]++;
			for(int j=1;j<=z;j++)
			{
				d+=a[i-j].xiayiwei;
			}
			z++;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt=max(ans[i],cnt);
	}
	cout<<cnt;
	return 0;
} 
