#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
typedef long long ll;
const int N=2e6+5;
int c,t,n;
ll d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(;t--;){
		scanf("%d%lld",&n,&d);
		rep(i,1,n)
			scanf("%lld",&a[i]);
		if(n<4){
			puts("0");
			continue;
		}
		if(c==0||c==12){
			ll gc=a[2]-a[1];
			ll jg=max((ll)2,d/gc);
			if(gc*2>d){
				puts("0");
				continue;
			}
			printf("%lld\n",(n-jg)*(n-jg-1)/2);
		}
		if(c==13||c==14){
			if(a[n]-a[1]<=d){
				puts("0");
				continue;
			}
			bool f=0;
			rep(i,1,n){
				if(a[i]-a[1]>d)
					f=i;
			}
			if(f<4){
				puts("0");
				continue;
			}
			printf("%lld\n",(f-3)*(n-f+1));
		}
	}
	return 0;
}
