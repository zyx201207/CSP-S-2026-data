#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back

namespace kanade
{
	ll read()
	{
		ll ans=0,fs=1;
		char ch=getchar();
		while(ch<'0'||ch>'9')
		{
			if(ch=='-')fs=-1;
			ch=getchar(); 
		}
		while(ch>='0'&&ch<='9')
		{
			ans=ans*10+ch-'0';
			ch=getchar(); 
		}
		return ans*fs;
	}
	
	ll Q[500010],A[500010];
	
	
	int main()
	{
		int n=read();
		ll m=read();
		for(int i=1;i<=n;i++)
		{
			A[i]=read();
		}
		sort(A+1,A+1+n);
		for(int i=1;i<=n;i++)
		{
			Q[i]=Q[i-1]+A[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int l=1,r=i-1,p=i;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(A[i]*(i-mid+1)-(Q[i]-Q[mid-1])<=m)
				{
					p=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
		//	cout<<i<<' '<<p<<' '<<A[i]*(i-p+1)-(Q[i]-Q[p-1])<<endl;
			ans=max(ans,i-p+1);
		}
		cout<<ans<<'\n';
		return 0;
	}
} 

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	kanade::main();
	return 0;
}

//就数你就数你就数你 
