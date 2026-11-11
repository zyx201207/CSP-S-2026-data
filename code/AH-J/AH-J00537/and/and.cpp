#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long LL;
LL n,m,a[N],ans[N],tot=1,maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
	//cout<<t<<" "<<(3<<1)<<endl;
	for(LL i=30;i>=0;i--){
		LL num=(maxn|(1<<i));
		ans[tot]=i;//若加上当前位，变换成的数
		LL cnt=0;//满足当前构造的数 个数
		for(LL j=1;j<=n;j++){//判断可否变换，满足当前构造的数>=m
			bool ok=1;//判断可否变换
			for(LL k=1;k<=tot;k++){//是否满足当前构造的数
				if(!(a[j]&(1<<ans[k]))){ok=0;break;}
			}
			if(ok) cnt++;
			//if(n-j+cnt<m) break;//剩余数+满足当前构造的数 个数<=m
		}//cout<<i<<endl;
		if(cnt>=m){maxn=num;tot++;}//可变换
	}
	printf("%lld",maxn);
	return 0;
}
