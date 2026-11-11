#include <bits/stdc++.h>
using namespace std;
#define int long long
#define OI ios::sync_with_stdio(0);cin.tie(0)
#define end '\n'
#define pii pair<int,int>

const int N=2e5+5;
int n,m,a[N];
bool isa=1;

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

//	freopen("test3.in","r",stdin);
	
	OI;
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if (__builtin_popcountll(a[i]+1)!=1) isa=0;
	}
	
	sort(a+1,a+n+1);
	int maxa=a[n];
	
	if (n<=20)
	{
		int ans=0;
		for (int i=0;i<(1<<n);i++)
		{
			if (__builtin_popcountll(i)==m)
			{
				int res=-1;
				for (int j=0;j<n;j++)
				{
					int num=a[j+1];
					if ((i>>j)&1) 
					{
						if (res==-1) res=num;
						else res&=num;
					}
				}
				
				ans=max(ans,res);
			}
		}
		
		cout<<ans<<endl;
		return 0;
	}
	if (n==m)
	{
		int ans=a[1];
		for (int i=2;i<=n;i++) ans&=a[i];
		
		cout<<ans<<endl;
		return 0;
	}
	else if (isa==1)
	{
		sort(a+1,a+n+1,greater<int>());
		
		int ans=a[1];
		for (int i=2;i<=m;i++) ans&=a[i];
		
		cout<<ans<<endl;
		return 0;
	}
	else if (m==1)
	{
		cout<<a[n]<<endl;
		return 0;
	}
	else if (m==2)
	{
		int ans=0;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				ans=max(ans,(a[i]&a[j]));
		
		cout<<ans<<endl;
		return 0;
	}
	else if (maxa<4)
	{
		int cnt[10]={0,0,0,0,0};
		for (int i=1;i<=n;i++) cnt[a[i]]++;
		
		int ans=0;
		if (cnt[3]>=m) ans=3;
		else if (cnt[2]+cnt[3]>=m) ans=2;
		else if (cnt[2]+cnt[1]>=m) ans=1;
		else ans=0;
		
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
