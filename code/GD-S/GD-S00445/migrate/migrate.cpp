#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>
typedef long long ll;
namespace my{
	template<typename now_type>now_type max(now_type x,now_type y){return x>y?x:y;}
	template<typename now_type>now_type min(now_type x,now_type y){return x<y?x:y;}
};
const int intinf=1e9;
void solve_n2logn(const int &n,const ll &d,const std::vector<ll>&a){
	ll ans=0;
	for(int i=1;i<=n;i++){
		std::vector<int>cnt(n+1,0);
		std::vector<int>sum(n+1,0);
		sum[i]=1;
		for(int j=i+1;j<=n;j++) cnt[j]=intinf;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[j-1]>d) break;
			int left=std::lower_bound(a.begin()+i,a.end(),a[j]-d)-a.begin();
			left=my::min(left,j-1);
			left=my::max(left,i);
			int right=std::upper_bound(cnt.begin()+left,cnt.end(),cnt[left])-cnt.begin()-1;
			right=my::min(right,j-1);
			right=my::max(right,left);
			sum[j]=sum[right]-sum[left-1];
			cnt[j]=cnt[left]+1;
//			printf("%d %d cnt=%d sum=%d l=%d r=%d\n",i,j,cnt[j],sum[j],left,right);
			if(sum[j]==2) ans++;
			sum[j]+=sum[j-1];
		}
	}
	printf("%lld\n",ans);
	return;
}
void solve(int c){
	int n;
	ll d;
	scanf("%d%lld",&n,&d);
	std::vector<ll>a(n+1);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(1<=c&&c<=10){
		solve_n2logn(n,d,a);
		return;
	}
	
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	scanf("%d",&c);
	int T=1;
	scanf("%d",&T);
	while(T--) solve(c);
	return 0;
}
