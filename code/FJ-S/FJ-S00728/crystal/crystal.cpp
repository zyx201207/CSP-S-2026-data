#include<bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
int n,m,a[N],sum[N],ans;
int w(int l,int r){
	return sum[r]-sum[l-1];
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int now=i;
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)>>1;
			int len=i-mid;
			if(a[i]*len-w(mid,i-1)>m){
				l=mid+1;
			}
			else{
				r=mid-1;
				now=mid;
			}
		}
		ans=max(ans,i-now+1);
	}
	cout<<ans;
	return 0;
}

