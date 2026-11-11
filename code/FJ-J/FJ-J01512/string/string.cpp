#include<bits/stdc++.h>
#define int long long
#define il inline
#define pii pair<int,int>

using namespace std;
const int maxn=2e5+5;
int n,a[maxn],sum,ans,l[maxn],r[maxn];
char c[maxn];
il int read()
{
	int res,f=1;
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9')
		if(ch=='-')
			f=-1;
	res=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res*f;
}

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l[i]=sum+1;
		sum+=a[i];
		r[i]=sum;
	}
	sum++;
	for(int i=1,j=n;;)
	{
		if(i>=j)
			break;
		int l1=sum-r[i],r1=sum-l[i],l2=l[j],r2=r[j];
		if(c[i]!=c[j])
		{
			if(l1<=l2&&r1<=r2)
				ans+=r1-l2+1;
			if(l1<=l2&&r1>r2)
				ans+=r2-l2+1; 
			if(l1>l2&&r1<=r2)
				ans+=r1-l1+1;
			if(l1>l2&&r1>r2)
				ans+=r2-l1+1;
		}
		if(l1<l2)
			j--;
		if(l1==l2)
		{
			i++;
			j--;
		}
		if(l1>l2)
			i++;
	}
	cout<<ans<<'\n'; 
	return 0;
}

