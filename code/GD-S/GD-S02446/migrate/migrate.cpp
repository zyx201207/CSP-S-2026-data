#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll k=0,f=1;
	int c=getchar();
	for(;!isdigit(c);c=getchar()){if(c=='-')f=-1;}
	for(;isdigit(c);c=getchar()){k=k*10+(c&15);}
	return f*k;
}
const int maxn=2e6+100;
const ll inf=3e18;
ll c,t,n,d;
ll a[maxn];
ll dif[maxn];
int sum=0;
int cnt=0;
int minn=maxn+100;
void dfss(int x,int y){
	if(x==y){
		if(sum<minn){
			cnt=1;
			minn=sum;
		}else if(sum==minn){
			cnt++;
		}
		return;
	}
	for(int i=y;i>x;i--){
		if(a[i]-a[x]>d)continue;
		sum++;
		if(i!=y&&sum>minn)continue;
		dfss(i,y);
		sum--;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
//		if(n>maxn) continue;
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
//		//判等差数列
//		for(int i=1;i<=n;i++){
//			dif[i]=a[i]-a[i-1];
//		} 
//		bool ok=1;
//		for(int i=3;i<=n;i++){
//			if(dif[i]!=dif[i-1]){
//				ok=0;
//			}
//		}
//		if(ok&&n>=2){
//			ll step=d/dif[2];
//			if(d%dif[2]!=0)step++;
//			//一次要跨这么多格
//			if(step>=n-1){
//				printf("0\n");
//				continue;
//			}else if(2*step>=n){
//				ll res=step*(n+1-2*step)+(3+step)*(step-2)/2;
//				printf("%lld\n",res);
//			}else{
//				ll res=(n-3-step)*(1+n-3-step);
//				printf("res%lld\n",res);
//			}
//		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,cnt=0;
				minn=maxn+100;
				dfss(i,j);
				if(cnt==2){
					ans++;
				} 
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
