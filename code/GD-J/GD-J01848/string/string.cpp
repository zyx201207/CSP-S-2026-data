#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node
{
	int len;
	char c;
};
vector <node> a;
int s1[N],s2[N];
int n;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	a.push_back({0,' '});
	for(int i=1;i<=n;i++)
	{
		int len;
		char c;
		cin>>len;
		cin>>c;
		a.push_back({len,c});
		s1[i]=s1[i-1]+len;
	}
	int mid_=(1+s1[n])>>1;
	int midp=lower_bound(s1+1,s1+n+1,mid_)-s1;
	char midch=a[midp].c;
	a.erase(a.begin()+midp);
	a.insert(a.begin()+midp,{mid_-s1[midp-1],midch});
	if(mid_<s1[midp]) a.insert(a.begin()+midp+1,{s1[midp]-mid_,midch});
	n=a.size()-1;
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<':'<<"len:"<<a[i].len<<' '<<a[i].c<<'\n';
		s1[i]=s1[i-1]+a[i].len;
	}
	for(int i=n;i>=1;i--)
	{
		s2[i]=s2[i+1]+a[i].len;
	}
	midp=lower_bound(s1+1,s1+n+1,mid_)-s1;
	mid_=(1+s1[n])>>1;
	int ans=0;
	for(int i=1;i<=midp;i++)
	{
		//if(i==midp&&(s1[n]&1)) continue;
		int l=0,r=n+1;
		while(l+1<r)
		{
			int mid=l+r>>1;
			if(s2[mid]>=s1[i]) l=mid;
			else r=mid;
		}
		int curl=l;
		l=0,r=n+1;
		while(l+1<r)
		{
			int mid=l+r>>1;
			if(s2[mid]>s1[i-1]) l=mid;
			else r=mid;
		}
		int curr=l;
		//第 i 段，对应第 curl 至 curr 中的某些部分
		int sum=0;
		for(int j=curl+1;j<curr;j++)
		{
			if(a[i].c!=a[j].c) ans+=a[j].len;
			sum+=a[j].len;
		}
		int lstlft=s1[i-1]-s2[curr+1];
		int rlft=a[curr].len-lstlft;
		if(a[i].c!=a[curr].c) ans+=rlft;
		int llft=a[i].len-sum-rlft;;
		if(a[i].c!=a[curl].c) ans+=llft;
		//cout<<curl<<' '<<curr<<' '<<llft<<' '<<rlft<<' '<<a[curr].c<<' '<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
