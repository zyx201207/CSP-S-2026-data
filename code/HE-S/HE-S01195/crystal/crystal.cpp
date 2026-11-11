#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ls(u) ((u)<<1)
#define rs(u) ((u)<<1|1)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pb push_back
inline int read(){
  char c=getchar();int d=0,f=0;
  while(!isdigit(c)){
	if(c=='-') f=1;c=getchar();
  }while(isdigit(c)){
	d=d*10+c-'0';c=getchar();
  }return f?-d:d;
}
const int N=5e5+10;
int n,m,sum[N],a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	} 
	ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid=0;
		while(l<r){
			mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	
  return 0;
}

