#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,sum[500005],s,ans,a[500005];
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=max((n+1)/2-n/10-n/8-500-n/(int)(log2(n)),0ll),r=min((n+1)/2+n/3+700+n/(int)(log2(n)),n);
	//cout<<l<<" "<<r<<endl;
	for(int i=a[l];i<=a[r];i++){
		int pos=upper_bound(a+1,a+1+n,i)-a-1,mm=m,res=0;
		//cout<<i<<"-"<<pos<<":";
		for(int j=pos;j>=1;j--){
			if(mm>=i-a[j])mm-=i-a[j],res++;
		}
		//cout<<res<<endl;
		ans=max(res,ans);
	}
	cout<<ans<<endl;
//	int l=2ll*s-maxx,r=maxx;
//	while(l<=r){
//		int mid=(l+r)>>1;
//		if(check(mid)){
//			r=mid-1,best=mid;
//		}else{
//			l=mid+1;
//		}
//	}
//	cout<<ans<<" "<<best<<endl;
	return 0;
} 
