#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
ll choose(int n,int m,int t,int cnt,ll sum){//第t个数开始选，选了cnt个，值为sum 
	if(m+1==cnt||n+1==t) return sum;
	ll s1=0,s2=0;
	for(int i=t;i<=n;i++){
		s1=max(s1,choose(n,m,i+1,cnt+1,sum&a[i]));
		s2=max(s2,choose(n,m,i+1,cnt,sum));
	}
	return max(s1,s2);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=2000){
		if(n<=20){
			ll maxn=max(choose(n,m,1,0,0),choose(n,m,1,1,a[1]));
			printf("%lld",maxn);
		}else if(m==1){
			sort(a+1,a+1+n,greater<ll>());
			printf("%lld",a[1]);
		}else if(m==n){
			ll sum=a[1];
			for(int i=2;i<=n;i++){
				sum&=a[i];
			}
			printf("%lld",sum);
		}else if(m==2){
			ll maxn=-0x7f7f7f7f;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					maxn=max(maxn,a[i]&a[j]);
				}
			}
			printf("%lld",maxn);
		}
	}else{
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=i-1) flag=0;
		}
		if(flag==1){//特殊性质B 
			sort(a+1,a+1+n,greater<ll>());
			if(a[1]%2==0) printf("%lld",n-m+1);
			else printf("%lld",n-m);
		}else{//特殊性质A 
			sort(a+1,a+1+n,greater<ll>());
			printf("%lld",a[m]);
		} 
	}
	return 0;
}
