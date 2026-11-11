#include<bits/stdc++.h>
#define LL long long
#define INF 1000000000000000
#define rep(i,a,b,g) for(LL i=a;i<=b;i+=g)
using namespace std;
LL n,m,a[500010],b[500010],s[500010],mc;
unordered_map<LL,LL>f;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	a[0]=b[0]=-INF;
	rep(i,1,n,1)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	rep(i,1,n,1)
	{
		b[i]=a[i]+1100000000000;
		s[i]=s[i-1]+b[i];
	}
	LL le=0;
	rep(i,1,n+1,1)
	{
		if(a[i]!=a[i-1])
		{
			if(i!=1)
			{
				f[a[i-1]]=le;
				le=0;
			}
		}
		le++;
	}
	LL l,r,mid;
	rep(i,1,n,1)
	{
		if(a[i]==a[i-1])continue;
		l=0;
		r=i;
		while(l+1<r)
		{
			mid=l+r>>1;
//			cout<<i<<' '<<mid<<':'<<(i-mid)*a[i]-(s[i-1]-s[mid-1])<<endl;
			if((i-mid)*b[i]-(s[i-1]-s[mid-1])<=m)r=mid;
			else l=mid;
		}
//		cout<<i<<' '<<r<<endl;
//		if(f[a[i]]+(i-r)==4237)
//		{
//			cout<<i<<' '<<r<<endl;
//			cout<<b[i]<<' '<<s[i-1]<<endl;
//		}
		mc=max(mc,f[a[i]]+(i-r));
	}
//	LL su1=0,su2=0;
//	rep(i,1,4236,1)
//	{
//		su1+=a[4237]-a[i];
//		su2+=b[i];
//	}
//	cout<<su1<<' '<<su2<<endl;
	cout<<mc<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
