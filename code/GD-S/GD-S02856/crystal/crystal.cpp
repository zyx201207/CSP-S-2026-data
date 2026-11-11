#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define LL long long
using namespace std;
const int N=5e5+10;
const int INF=1e9+10;
inline LL read()
{
	LL x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-48;
	return x*f;
}

int n,ans;
LL m,a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	rep(i,1,n)
	{
		a[i]=read();
	}
	sort(a+1,a+1+n);
	rep(i,1,n)
	{
		s[i]=s[i-1]+a[i];
	}
	rep(i,1,n)
	{
		int l=1,r=i,mid,pos=i;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)
			{
				pos=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
//		cout<<i<<"::"<<pos<<endl;
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}

