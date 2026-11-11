#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],l=0,r,ls,qzh1[N],qzh2[N],qzh3[N];
inline long long getlen(long long gl,long long gr)
{
	return qzh2[gr]-(gl-1)*qzh1[gr]+qzh3[gl-1];
}

inline long long min(long long a,long long b)
{
	if(a>b)
	{
		return b;
	}
	return a;
}

inline int check(long long mid)
{
	long long output=0x3f3f3f3f3f3f3f;
	for(int i=1;i<=n-mid+1;i++)//枚举区间：[i,i+mid-1] 
	{
		output=min(output,getlen(i,i+mid-1));
	}
	//cout<<"最小区间花费："<<output<<"\n";
	return output<=m;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++)
	{
		ls=a[i]-a[i-1];
		qzh1[i]=qzh1[i-1]+ls;
		qzh2[i]=qzh2[i-1]+ls*(i-1);
		qzh3[i]=qzh3[i-1]+qzh1[i];
	}
	r=n+1;
	while(l+1<r)//枚举区间长度len 
	{
		long long mid=(l+r)/2;
		//cout<<"-----------------\n枚举区间长度为："<<mid<<"\n";
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
		//cout<<"-----------------\n";
	}
	cout<<l;
	return 0;
}
