#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
int n;
LL m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	LL tmp=0;
	int ans=1,l=1,r=1;//r :r=end-->cost all
	while(l<=r){
		if(l>n||r>n)break;
		if(tmp<=m){
			ans=max(ans,r-l+1);
			tmp+=(a[r+1]-a[r])*(r-l+1);
			r++;//*r move toward right,cost++
		}
		else{
			tmp-=(a[r]-a[l]);
			l++;
		}
	}
	printf("%d",ans);
	return 0;
}
