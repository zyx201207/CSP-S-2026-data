#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
namespace my{
	template<typename now_type>now_type max(now_type x,now_type y){return x>y?x:y;}
	template<typename now_type>now_type min(now_type x,now_type y){return x<y?x:y;}
};
void solve(){
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	std::vector<ll>a(n+2);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a.begin()+1,a.begin()+n+1);
	int l=1,r=0;
	ll sum=0;
	int ans=0;
	while(r<=n){
		if(l>r) sum+=a[++r];
		else if((r-l+1)*a[r]-sum<=m){
			ans=my::max(ans,r-l+1);
			sum+=a[++r];
		}
		else{
			sum-=a[l];
			l++;
		}
	}
	printf("%d",ans);
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
