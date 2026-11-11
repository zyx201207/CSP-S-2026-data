#include<bits/stdc++.h>//long long
using namespace std;
const long long N=5e5+11;
long long n,m,a[N],sum[N];
//inline long long checkk(long long l,long long r,long long z)
//{
//	long long mid,ans=l-1ll;
//	while(l<=r)
//	{
//		mid=(l+r)>>1ll;
//		if(a[mid]<=z)
//			l=mid+1ll,ans=mid;
//		else
//			r=mid-1ll;
//	}
//	cout<<'+'<<z<<' '<<ans<<'-';
//	return ans;
//}
//inline bool check(long long l,long long r)
//{
//	long long mid,ans=0ll,s,t;
////	mid=round((sum[r]-sum[l-1])*1.0/(r-l+1)*1.0);
////	cout<<l<<' '<<r/*<<' '<<mid<<' '<<s<<' '<<t<<endl*/;
////	s=checkk(l,r,mid-1);//<mid
////	t=checkk(l,r,mid);
//	t=s=(l+r)>>1;
//	mid=a[s];
////	cout<<endl;
//	return ((s-l+1)*mid-(sum[s]-sum[l-1]))+(sum[r]-sum[t]-(r-t)*mid)<=m;
//}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long dan=0ll,l=1ll;
	cin>>n>>m;
//	cout<<n<<' '<<m<<endl;
	for(long long i=1; i<=n; i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(long long i=1; i<=n; i++)
		sum[i]=sum[i-1]+a[i];
//	r=1;
//	for(long long l=1; l<=n; l++)
//	{
//		while(r+1<=n && check(l,r+1))
//			r++;
////		cout<<l<<' '<<r<<endl;
//		dan=max(dan,r-l+1);
//	}
	for(long long r=1; r<=n; r++)
	{
		while(a[r]*(r-l+1)-(sum[r]-sum[l-1])>m)
			l++;
		dan=max(dan,r-l+1);
	}
	cout<<dan;
	return 0;
}
/*

5 5
1 2 4 8 9

5 5
1 2 4 4 8

5 5
3 4 4 4 8

5 8
-3 -1 2 2 7

15:44
给自己气笑了
依旧满分阅读理解 


*/
