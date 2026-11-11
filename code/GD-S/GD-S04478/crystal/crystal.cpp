#include<bits/stdc++.h>
#define f1(i,x,n,y) for(int i=x;i<=n;i+=y)
#define f2(i,x,n,y) for(int i=x;i>=n;i-=y)
#define f3(i,x,n,y) for(int i=x;i<n;i+=y)
#define f4(i,x,n,y) for(int i=x;i>n;i-=y)
#define du double
#define st string
#define w while
#define int long long
using namespace std;
int n,m,a[519049],b[518834],c[513785],k=1,maxn=-1,f;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	f=m;
	f1(i,1,n,1)
	{
		cin>>b[i];
	}
	sort(b+1,b+1+n);
	f1(i,2,n,1)
	{
		b[i]-=b[1]-1;
	}
	b[1]=1;
	f1(i,1,n,1)
	{
		a[b[i]]++;
		c[i]=b[i]-b[i-1];
	}
	f3(i,1,n,1)
	{
		k=i;
		if(b[i]==b[i+1])
		{
			k++;
			continue;
		}
		w(1)
		{
			cout<<i<<" "<<k-i+1<<" "<<m<<" "<<b[i]<<" "<<c[k+1]<<" "<<a[b[i]]<<"\n";
			if(m>=(k-i+1)*c[k+1] && (k-i+1)<=n && b[i]<=b[n])
			{
				b[i]+=c[k+1];
				m-=(k-i+1)*c[k+1];
				k+=a[b[i]];
			}
			else
			{
				break;
			}
		}
		k-=i-1;
		maxn=max(maxn,k);
		m=f;
	}
	cout<<maxn;
	return 0;
}
