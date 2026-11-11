#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
using ll = long long;
const int N=5e5+5;
int n;
ll a[N],m;

ll read(){
	ll x=0,t=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*t;
}
int ans,f[N];
ll sum[N];

bool check(int i,ll mid){
	return m<(i-mid+1)*a[i]-(sum[i]-sum[mid-1]);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(check(i,mid)){l=mid+1;}
			else r=mid;
		}
		f[i]=i-l+1;
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}//yellow or orange...
// LIFE'S NOT OUT TO GET YOU!
