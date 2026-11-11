#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans,vis[200010],now=2147483647;
int cnt0,cnt1,cnt2,cnt3;
bool allt=1,allo=1;
bool cmp(int x,int y)
{
	return (x>y);
}
void mj(int k,int nownow,int cnt)
{
	if(k>=n+1)
	{
		if(cnt!=m) return ;
		ans=max(ans,nownow);
		return ;
	}
	if(n+1+cnt-k<m) return ;
	if(nownow<ans) return ;
	if(cnt>m) return ;
	mj(k+1,nownow&a[k],cnt+1);
	mj(k+1,nownow,cnt);
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(pow(2,(int)(log2(n)))!=n) allo=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) cnt0++;
		if(a[i]==1) cnt1++;
		if(a[i]==2) cnt2++;
		if(a[i]==3) cnt3++;
		if(pow(2,(int)log2(a[i]+1))!=a[i]+1) allt=0;
		if(a[i]!=i-1) allo=0;
	}
	sort(a+1,a+n+1,cmp);
	if(n<=20)
	{
		ans=0;
		mj(1,now,0);
		cout << ans;
		return 0;
	}
	if(n<=2000)
	{
		if(m==1)
		{
			cout << a[1];
			return 0;
		}
		if(m==n)
		{
			for(int i=1;i<=n;i++) now&=a[i];
			cout << now;
			return 0;
		}
		if(m==2)
		{
			ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<i;j++)
				{
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout << ans;
			return 0;
		}
	}
	if(a[1]<=3)
	{
		if(cnt3>=m) cout << 3;
		else if(cnt3+cnt2>=m) cout << 2;
		else if(cnt3+cnt1>=m) cout << 1;
		else cout << 0;
		return 0;
	}
	if(allt)
	{
		cout << a[m];
		return 0;
	}
	if(allo)
	{
		cout << n-pow(2,ceil(log2(m)));
		return 0; 
	}
	return 0;
}
