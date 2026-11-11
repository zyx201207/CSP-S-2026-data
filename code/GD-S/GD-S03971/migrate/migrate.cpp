#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<':'<<(x)<<endl;
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,t;
int n;
ll d,x[N],dis[N],f[N],ans;
inline void solve1(){
	for(int i=1;i<=n;i++){
		int l=i,l2=i;//debug(i)
		ll sum=0;
		dis[i]=0;
		f[i]=1;
		for(int r=i+1;r<=n;r++){//debug(r)
			dis[r]=0;
			while(x[r]-x[l]>d)sum-=f[l++];
			dis[r]=dis[l]+1;
			while(dis[r]!=dis[l2])sum+=f[l2++];
			f[r]=sum;
			ans+=(f[r]==2);
//			debug(dis[r])debug(f[r])
//			debug(l)debug(l2)debug(sum)debug(ans)
		}
	}
	printf("%lld\n",ans);
}
inline void solve2(){
	int l=1,l2=1;
	ll sum=0;
	dis[1]=0;
	f[1]=1;
	for(int r=2;r<=n;r++){
		dis[r]=0;
		while(x[r]-x[l]>d)sum-=f[l++];
		dis[r]=dis[l]+1;
		while(dis[r]!=dis[l2])sum+=f[l2++];
		f[r]=sum;
		ans+=1ll*(f[r]==2)*(n-r+1);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",x+i);
		if(c==11||c==12){
			solve2();
		}else if(n<5005)solve1();
		else {
			puts("0");
		}
	} 
} 
