//GZ-J00449 曾嵩 兴义市弘毅中学
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=20050;
int n,m;
ll a[MAXN];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	//for(int i=0;i<n;i++) printf("%lld\n",a[i]);
	if(m=1){
		sort(a,a+n,cmp);
		printf("%lld",a[0]);
		return 0;
	}
	if(m==n){
		long long ans=a[0];
		for(int i=1;i<n;i++)
			ans&=a[i];
		printf("%lld",ans);
		return 0;
	}
	return 0;
} 
