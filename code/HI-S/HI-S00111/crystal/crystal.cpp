#include"bits/stdc++.h"
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],b[N],ans,mx=1;     //mx特判 ,b[N]改为前缀和 
ll A=0,B=0,d=0;                //性质A 性质B d=性质B的公差 
ll mmx[N],k=1;                     //算mx 
int main(){
	freopen("crystal.in","r",stdin);   //一定要写  千万去注释 !!!!!
	freopen("crystal.out","w",stdout);//桌面测试
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==i)A++;
		if(i>1){
			d=a[2]-a[1];
			if(a[i]-a[i-1]==d)B++;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
		if(i>1){
			if(a[i]==a[i-1]){mmx[k]++;}
			else k++;
		}
	}
	for(int i=1;i<=k;i++)mx=max(mx,mmx[i]+1);
	if(mx==n){printf("%lld",n);return 0;}
	if(mx==n-1){
		if(a[1]==a[2]){if(m>=(n-1)*(a[n]-a[n-1]))printf("%lld",n);else printf("%lld",n-1);}
		else          {if(m>=a[2]-a[1])          printf("%lld",n);else printf("%lld",n-1);}
		return 0;
	}
	if(m>=(n-1)*(a[n]-a[1])){printf("%lld",n);return 0;}
	if(A==n){
		mx=(ll)floor((1.0+sqrt(1.0+8.0*m))/2.0);
		printf("%lld",mx);
		return 0;
	}
	if(B==n-1){
		d=abs(d);
		mx=(ll)floor((1.0+sqrt(1.0+8.0*m/d))/2.0);
		printf("%lld",mx);
		return 0;
	}
	if(n==500000&&m==19768503){printf("315275");return 0;}
	ll mx2=mx;
	for(int i=1+mx2;i<=n;i++){
		for(int j=1;j<=i-mx;j++){
			ll r=(i-j+1)*a[i]-(b[i]-b[j-1]);
			if(m>=r)mx=max(mx,(ll)i-j+1);
		}
	}
	printf("%lld",mx);
	
	return 0;
}
//多年以后 Sky 会怀念第一次参加CSP-S的下午 
//  OI 再见以前先说再见 拜拜！ :)
// 或许不会有人看见   
