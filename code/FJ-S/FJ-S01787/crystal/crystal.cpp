#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int sign=1,cnt=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	sign=-1;
		c=getchar();
	}
	while(isdigit(c)){
		cnt=(cnt<<1)+(cnt<<3)+(c^48);
		c=getchar();
	}
	return sign*cnt;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	while(x>9){
		write(x/10);
		putchar(x%10+'0');
	}
}
const int N=5e5+10;
int n,m;
int a[N];
int lf1[N],rt1[N],lf2[N],rt2[N],f[N];
void init(){
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		f[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<=n-1;i++){
		lf1[i]=lf1[i-1]+f[i];
		lf2[i]=lf2[i-1]+lf1[i];
	}
	for(int i=n-1;i>=1;i--){
		rt1[i]=rt1[i+1]+f[i];
		rt2[i]=rt2[i+1]+rt1[i];
	}
//	for(int i=1;i<=n;i++){printf("%lld ",lf1[i]);};printf("\n");
//	for(int i=1;i<=n;i++){printf("%lld ",lf2[i]);};printf("\n");
//	for(int i=1;i<=n;i++){printf("%lld ",rt1[i]);};printf("\n");
//	for(int i=1;i<=n;i++){printf("%lld ",rt2[i]);};printf("\n");
}
bool check(int x){
//	printf("%lld\n",x);
	int len=(x-1)>>1;
//	printf(">>>%lld %lld",len+1,n-len-1);
	int lx,rx,ans;
	if(x%2){
		for(int i=len+1;i<=n-len-1;i++){
			lx=i-len,rx=i+len;
			ans=(rt2[lx]-rt2[i]-rt1[i]*len)+(lf2[rx]-lf2[i]-lf1[i]*len);
//			printf(">>%lld\n",ans);
			if(ans<=m)	return 1;
		}
	}else{
		int i=len+1;
		lx=i-len,rx=i+len+1;
		int ans1=(rt2[lx]-rt2[i]-rt1[i]*len)+(lf2[rx]-lf2[i]-lf1[i]*(len+1));
		if(ans1<=m)	return 1;
		i=n-len-1;
		lx=i-len-1,rx=i+len;
		int ans2=(rt2[lx]-rt2[i]-rt1[i]*(len+1))+(lf2[rx]-lf2[i]-lf1[i]*len);
		if(ans2<=m)	return 1;
		for(i=len+2;i<=n-len-2;i++){
			lx=i-len,rx=i+len+1;
			int ans1=(rt2[lx]-rt2[i]-rt1[i]*len)+(lf2[rx]-lf2[i]-lf1[i]*(len+1));
			lx=i-len-1,rx=i+len;
			int ans2=(rt2[lx]-rt2[i]-rt1[i]*(len+1))+(lf2[rx]-lf2[i]-lf1[i]*len);
			ans=min(ans1,ans2);
//			printf(">%lld %lld\n",ans1,ans2);
			if(ans<=m)	return 1;
//		printf(">>%lld %lld %lld\n",x,i,ans);
		}
	}
	return 0;
}
void Izumi(){
	n=read(),m=read();
	a[1]=read();
	for(int i=2;i<=n;i++){
		a[i]=read();
	}
	init();
	if(n>5000){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=i*(a[2]-a[1]);
			if(sum>=(m/2))	break;
		}
		printf("%lld",sum*2+1);
		return;
	}
	int l=1,r=n-1;
	while(l<r){
		int mid=(l+r+1)>>1;
//		printf("Ck:%lld\n",mid);
		if(check(mid))	l=mid+1;
		else	r=mid;
//		printf("L%lld %lld\n",l,r);
	}
	printf("%lld",l-1);
}
signed main(){
	freopen("crysta.in","r",stdin);
	freopen("crysta.out","w",stdout);
	Izumi();//ÓÀÔ¶Ï²»¶Èª´Ë·½ 
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

7 3
1 2 3 4 5 6 7
*/ 
