//GZ-S00061 zhangbin zunyisizhong
#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define repp(i,a,b) for(int i=a;i<=b;i++)
#define reqq(i,a,b) for(int i=a;i>=b;i--)

ll rd()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
const int N=5e5+5;
ll a[N],b[N],c[N];
ll n,m;
int ans=0;
bool check(int mid,int r)
{
//	printf("%d %d %d\n",c[r],a[mid],r);
	int cur=(a[r]-a[mid-1])*(mid-1)+c[mid-1];
//	printf("%d ? %d\n",c[r],cur);
	if(m>=c[r]-cur) return 0;
	else return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd(),m=rd();
	repp(i,1,n) a[i]=rd();
	sort(a+1,a+1+n);
	repp(i,2,n) b[i]=a[i]-a[i-1];
	repp(i,2,n) c[i]=b[i]*(i-1)+c[i-1];
	
	//repp(i,1,n) printf("%d ",c[i]);
//	printf("%d\n\n",check(4,5));
	repp(i,1,n)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i)) l=mid+1;
			else r=mid;	
//			printf("%d : %d\n",l,r);
		}
//		printf("%d %d\n",l,i);
		ans=max(i-l+1,ans);
	}
	printf("%d",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

int n=rd(),m=rd();
	repp(i,1,n)
		a[i]=rd();
//	sort(a+1,a+1+n);
	repp(i,2,n) b[i]=a[i]-a[i-1];
//	repp(i,2,n) c[i]=b[i]*(i-1)+c[i-1];
//	repp(i,1,n) printf("%d ",c[i]);
*/ 
