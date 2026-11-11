#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>

inline int read(void);
inline void write(int);

const int N=5e5+5;
int n,m,a[N];

int pre[N];

int ans;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

//	freopen("crystal4.in","r",stdin);
	
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	
	if (n==1) 
	{
		write(a[1]);
		return 0;
	}
	
	sort(a+1,a+n+1);
	
	for (int i=1;i<=n;i++) 
	{
		pre[i]=pre[i-1]+a[i];
//		printf("pre[i]=%lld,",pre[i]);
	}
//	printf("\n");
	
	for (int i=1;i<=n;i++)
	{
		int l=1,r=i,res=i;
		while (l<=r)
		{
			int mid=l+((r-l)>>1);
			
			if ((i-mid+1)*a[i]-(pre[i]-pre[mid-1])<=m)
			{
				res=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		
		ans=max(ans,i-res+1);
	}
	
	write(ans);
	return 0;
}



inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while ('0'<=ch&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	
	return x*f;
}

inline void write(int x)
{
	if (x<0)
	{
		x=-x;
		putchar('-');
	}
	if (x>9) write(x/10);
	putchar(x%10^48);
	
	return ;
}
