#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],c[200005][31],mx,mxx,sum,vis[200005],ans[31],p,q[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	p=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long s=1,t=a[i],b=1;
		while(!(s>a[i]))
		{
			s*=2;
			b++;
		}
		s/=2;
		mx=max(mx,b-1);
		mxx=max(mxx,s);
		while(b--)
		{
			if(t>=s)
			{
				t-=s;
				c[i][b]=1;
				ans[b]++;
			}
			s/=2;
		}
	}
	while(mx)
	{
		long long cnt=0,pos=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				continue; 
			}
			if(!c[i][mx])
			{
				q[++pos]=i;
			}
			else
			{
				cnt++;
			}
		}
		if(cnt<m)
		{
			mxx/=2;
			mx--;
			continue;
		}
		if(cnt>=m)
		{
			for(int i=1;i<=pos;i++)
			{
				vis[q[i]]=1;
			}
			sum+=mxx;
		}
		mxx/=2;
		mx--;
	}
	cout<<sum;
	return 0;
}

