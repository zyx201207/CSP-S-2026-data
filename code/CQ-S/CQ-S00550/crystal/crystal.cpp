#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
const int N=5e5+5;
lo n,m,a[N],pre[N],mx;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(lo i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(lo i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(lo i=1;i<=n;i++)
	{
		lo l=1,r=i,mid=0,pos=i;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if((i-mid+1)*a[i]-pre[i]+pre[mid-1]<=m)
				r=(pos=mid)-1;
			else l=mid+1;
		}
		mx=max(mx,i-pos+1);
	}
	cout<<mx;
}
/*
¿´´íÌâÁË°¡ Öý±Ò 
*/
