#include <iostream>
#include <algorithm>
#define int long long
#define N 500005
using namespace std;
int n,m,a[N],sum[N],pre[N],ans;
int read(){
	int x=0;
	char ch=getchar();
	bool f=false;
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=true;
		}
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
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
		int l=1,r=i,pos=i;
		while(l<r){
			int mid=l+r>>1,tmp=a[i]*(i-mid)-(sum[i-1]-sum[mid-1]);
			if(tmp>m){
				l=mid+1;
			}else{
				r=mid;
				pos=mid;
			}
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}
