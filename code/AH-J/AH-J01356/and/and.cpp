#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],l[200001],r[200001],p[21],cnt[4],ans;
bool vis[200001];
void f(int m,int sum){
	if(m==0)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==true)continue;
		vis[i]=true;
		f(m-1,sum&a[i]);
		vis[i]=false;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=0;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
		printf("%d",ans);
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		printf("%d",ans);
	}
	else if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		}
		printf("%d",ans);
	}
	else if(m==n-1)
	{
		l[1]=a[1];
		r[n]=a[n];
		for(int i=2;i<=n;i++)
			l[i]=l[i-1]&a[i];
		for(int i=n-1;i>=1;i--)
			r[i]=r[i+1]&a[i];
		ans=max(l[n-1],r[2]);
		for(int i=2;i<n;i++)
			ans=max(ans,l[i-1]&r[i+1]);
		printf("%d",ans);
	}
	else if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			vis[i]=true;
			f(m-1,a[i]);
			vis[i]=false;
		}
		printf("%d",ans);
	}
	else
	{
		for(int i=1;i<=20;i++)p[i]=1<<i;
		bool f=true;
		for(int i=1;i<=n;i++)
		{
			bool g=false;
			for(int j=1;j<=20;j++)
			{
				if(a[i]==p[j]-1)
				{
					g=true;
					break;
				}
			}
			if(g==false)
			{
				f=false;
				break;
			}
		}
		if(f==true)
		{
			for(int i=1;i<=n;i++)
				ans=max(ans,a[i]);
			printf("%d",ans);
		}
		else
		{
			int k=0;
			for(int i=1;i<=n;i++)
				k=max(k,a[i]);
			if(k<4)
			{
				for(int i=1;i<=n;i++)
					cnt[a[i]]++;
				if(cnt[3]>=m)ans=3;
				else if(cnt[3]+cnt[2]>=m)ans=2;
				else if(cnt[3]+cnt[1]>=m)ans=1;
				else ans=0;
				printf("%d",ans);
			}
		}
	}
	return 0;
}
