#include<bits/stdc++.h>
namespace LMY{
	using std::min;
	using std::max;
	using std::pair;
	#define int long long
	#define pii pair<int,int>
	#define pip pair<int,pii>
	#define ppi pair<pii,int>
	#define ppp pair<pii,pii>
	#define lp first
	#define rp second
	#define edl putchar('\n')
	#define lowbit(x) ((x)&(-(x)))
	constexpr int inf=0x3f3f3f3f3f3f3f3f;
	int read()
	{
		int x=0,f=1;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
		while('0'<=ch&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
		return f*x;
	}
	void write(int x)
	{
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	void print(int x,char ed='\n'){write(x);putchar(ed);}
	constexpr int N=5*1e5+100,P=1e9+7;
	int n,m,a[N],sum[N];
	signed Main()
	{
		n=read(),m=read();
		for(int i=1;i<=n;i++) a[i]=read();
		std::sort(a+1,a+n+1);
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+a[i];
			if(a[i]*i-sum[i]<=m){ans=max(ans,i);continue;}
			int l=1,r=i;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid;
				else l=mid+1; 
			}
			ans=max(ans,i-l+1);
		}
		print(ans);
		return 0;
	}
}
signed main()
{
//	system("fc crystal.out crystal.ans");
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	return LMY::Main();
}
//Time Complexity: O(N*log2(N))
