#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],r;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int ans=1;
	int flag=3;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1) continue;
		r=a[2]-a[1];
		if(a[i]==a[i-1]+1&&flag!=0) flag=1;
		else if(a[i]-a[i-1]==r&&flag!=0) flag=2;
		else
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		int l=0,cn=0;
		for(int i=1;i<=N;i++)
		{
			l+=i;
			if(m>=l) cn++;
		}
		cout<<cn+1;
		return 0;
	}
	if(flag==2)
	{
		int l=0,cn=0;
		for(int i=1;i<=N;i++)
		{
			l+=r;
			if(m>=l) cn++;
		}
		cout<<cn+1;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int cnt=0,r=m;
		for(int j=i+1;j<=n;j++)
		{
			int x=a[i]-a[j];
			if(r>=x)
			{
				cnt++;
				r-=x;
			}
			else 
			{
				break;
			}
		}
		ans=max(cnt+1,ans);
	}
	cout<<ans;
	return 0;
}
