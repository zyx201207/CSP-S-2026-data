#include<bits/stdc++.h>

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif
using namespace std;
const int maxn=500005;

long long read(){
	long long x=0,flo=1,ch=gc();
	for(;!isdigit(ch);ch=gc()){
		if(ch=='-')flo=-1;
	}
	for(;isdigit(ch);ch=gc()){
		x=x*10+(ch^48);
	}
	return x*flo;
}


long long a[maxn],vis[maxn],b[maxn];
long long n,m;


long long check(int len){
	sort(b,b+len);
	long long ans=-1;
	for(long long i=0;i<len;i++){
		long long j=i,sum=0;
		while(sum<=m&&j<len){
			sum+=b[j];
			j++;
		}
		if(sum>m){
			j--;
		}
		ans=max(j-i,ans);
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	long long ans=-1;
	for(int i=1;i<=n;i++){
		int t=0;
		//memset(b,123456,sizeof(b));
		for(int j=1;j<=i;j++){
			b[t]=a[i]-a[j];
			if(b[t]<=0)b[t]=0;
			t++;
		}
		ans=max(ans,check(t));
	}
	printf("%lld",ans);
	return 0;
}
