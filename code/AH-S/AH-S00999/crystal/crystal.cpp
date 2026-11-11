#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
inline ll in(){
	ll x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
ll n,m,a[N],l=1,r=1,ans=1,sum,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=in();m=in();
	for (int i=1;i<=n;i++)a[i]=in();
	sort(a+1,a+1+n);
	while (r<=n){
		sum+=(a[r]-a[r-1])*(r-l);
		while (sum>m&&l<=r)sum-=a[r]-a[l++];
		ans=max(ans,r-l+1);
		r++;
	}
	printf ("%lld",ans);
	return 0;
}

