#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
const int N=5e5+5;
int n;
ll m;
ll a[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	rep(i,1,n)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n)
		pre[i]=pre[i-1]+a[i];
//	rep(i,1,n)
//		printf("%lld ",pre[i]);
	int ans=0;
	if(n<5005){
		int ans=0;
		rep(i,1,n){
			int res=1;
			rep(j,1,i){
				if(pre[i]-pre[j-1]+m>=a[i]*(i-j+1)){
					res=max(res,i-j+1);
				}
			}
			ans=max(ans,res);
		}
		printf("%d",ans);
		return 0;
	}
	rep(i,1,n){
		int res=1;
		int l=0,r=i+1;
		while(l+1<r){
			int mid=(l+r)/2;
			if(pre[i]-pre[mid]+m<a[i]*(i-mid+1))
				l=mid;
			else
				r=mid;
//			if(i==4){
//				printf("%d %d\n",l,r);
//			}
		}
//			printf("^^%d",l);
		ans=max(i-l,ans);
//		if(ans==5)
//			printf("&&%d ",i);
	}
	printf("%d",ans);
	return 0;
}
