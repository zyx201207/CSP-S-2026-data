#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int n,m,mx=-1,yu=(1<<30)-1;
int check(int mk)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if (a[i]>=mk) sum++;
		else break;
	}
	if (sum<m) return 0;
	else return 1;
}
int ck(int x)
{
	while(x>1)
	{
		if (x/2*2!=x) return 0;
		x/=2;
	}
	return 1;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int uu=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		uu+=ck(a[i]+1);
		mx=max(mx,a[i]);
		yu&=a[i];
	}
	if (m==1){cout<<mx; return 0;}
	else if (m==2&&n<=10000)
	{
		mx=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx<<endl;
		return 0;
	}
	else if (n==m){cout<<yu;return 0;}
	else if (mx==4)
	{
		sort(a+1,a+n+1);
		int yuu=(1<<30)-1;
		int a[5];
		a[1]=1;a[0]=0;
		for(int i=n;i>=1;i--)
		{
			if (a[i]==4&&a[i-1]==3) a[4]=i;
			if (a[i]==3&&a[i-1]==2) a[3]=i;
			if (a[i]==2&&a[i-1]==1) a[2]=i;
		}
		if (n-a[4]+1>=m){cout<<4; return 0;}
		else if (a[4]-a[3]>=m) {cout<<3; return 0;}
		else if (a[4]-a[2]>=m) {cout<<2; return 0;}
		else cout<<1;
		return 0;
	}
	else if (uu==n)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	int pw;
	for(int i=1;i<=30;i++)
	{
		if ((1<<i)>=mx)  
		{
			pw=i;
			break;
		}
	}
	sort(a+1,a+n+1,cmp);
	int l=1,r=1<<pw;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
} 
