#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=2*1e5+10;
struct Node{
	ll b;
	char c;
}a[maxn];
Node d[maxn];
ll s[maxn],leng;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i].b);
		a[i].c=getchar();
		a[i].c=getchar();
		s[i]=s[i-1]+a[i].b;
		leng+=a[i].b;
		d[i].b=a[i].b;
		d[i].c=a[i].c;
	}
	leng/=2;
	ll sum=0;
	ll ing=1;
	ll o=n;
	ll sx=a[ing].b;
	ll ans1=0;
	while(sum!=leng){
		if(sum+a[o].b<=sx){
			sum+=a[o].b;
			if(a[o].c!=a[ing].c){
				ans1+=a[o].b;
			}
			o--;
		}else{
			if(a[o].c!=a[ing].c) ans1+=sx-sum;
			a[o].b-=sx-sum;
			sum=sx;
			ing++;
			sx=s[ing];
		} 
		if(sx>leng){
			if(a[o].c!=a[ing].c) ans1+=leng-sum;
			sum=leng;
		}
	} 
	
	sum=0;
	ing=n;
	o=1;
	sx=s[n]-s[ing-1];
	ll ans2=0;
	while(sum!=leng){
		if(sum+d[o].b<=sx){
			sum+=d[o].b;
			if(d[o].c!=d[ing].c){
				ans2+=d[o].b;
			}
			o++;
		}else{
			if(d[o].c!=d[ing].c) ans2+=sx-sum;
			d[o].b-=sx-sum;
			sum=sx;
			ing--;
			sx=s[n]-s[ing-1];
		} 
		if(sx>leng){
			if(d[o].c!=d[ing].c) ans2+=leng-sum;
			sum=leng;
		}
	} 
	printf("%lld",min(ans1,ans2));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
