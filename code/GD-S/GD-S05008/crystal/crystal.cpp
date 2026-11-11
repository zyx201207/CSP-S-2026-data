#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5*100005+5;
int n,ans=1,tot;
ll m,a[N],d2[N],d3[N],d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld%lld%lld",&n,&m,&a[1],&a[2]);
	d=a[2]-a[1];
	for(int i=3;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d2[i]=a[i]-a[i-1];
		d3[i]=d2[i]+d2[i-1];
		if(a[i]-a[i-1]==d) tot++;
	}
	if(tot==n-1){//等差数列 
		//确定一个位置，往右找每一个数到此位置的间隔之和小于等于(m/d)
		int x=m/d;
		int sum=0,cnt=0;
		while(sum<x){
			cnt++;
			sum+=cnt;//sum*=2优化，不用算两次while 
		}
		ans+=cnt;
		if(sum<x){
			sum=0,cnt=1;
			x-=sum;
			while(sum<x){
				cnt++;
				sum+=cnt;
			}
			ans+=cnt;
		}
		printf("%d",min(ans,n));
		return 0;
	}
	//双指针（超时） 
	for(int i=1;i<=n;i++){
		int x=i,y=i;
		ll sum1=0,sum2=0;//sum1左边，sum2右边 
		bool f=0;
		while(1){
			f=0;
			if((sum1*2+d2[x]<sum2*2+d2[y+1] && x-1>=1 && sum1*2+d2[x]+sum2<=m) || (y==n && sum1*2+d2[x]+sum2<=m)){
				sum1=sum1*2+d2[x];
				x--;
				f=1;
			}
			if((sum1*2+d2[x]>sum2*2+d2[y+1] && y+1<=n && sum2*2+d2[y+1]+sum1<=m) || (x==1 && sum2*2+d2[y+1]+sum1<=m)){
				sum2=sum2*2+d2[y+1];
				y++;
				f=1;
			}
			if(!f) break;
		}
		ans=max(ans,y-x+1);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
