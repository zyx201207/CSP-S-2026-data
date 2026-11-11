#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
int len;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int len1=0,len2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i<=1002) len1+=a[i];
		else if(i>=1925) len2+=a[i];
		len+=a[i];
	}
//	printf("%lld %lld\n",len1,len2);
	int ans=0,now=0;
	int x=a[1],y=a[n];
	for(int i=1,j=n;;){
		int t=min(x,y);
//		printf("%lld %lld %lld %lld %lld \n",i,j,x,y,t);
		if(c[i]!=c[j]){
			ans+=min(t,len/2-now);
		}
		now+=t;
		if(now>=len/2) break;
		x-=t;
		y-=t;
		if(x==0) x=a[++i];
		if(y==0) y=a[--j];
	}
	printf("%lld",ans);
	return 0;
}
/*
3
2 a
12 b
1 c

*/
