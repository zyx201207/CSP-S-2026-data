#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],ans,minx=1e12,maxx=-1e12;
bool cmp(int a,int b){
	return a>=b;
}
int suan(int x){
	int cnt=0,tem[N],ans1=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x)
		tem[++cnt]=a[i];
	}
	sort(tem+1,tem+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(m-(x-tem[i])>=0){
			ans1++;
			m-=(x-tem[i]);
		//	cout<<m<<" ";
		}
	}
	return ans1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		minx=min(a[i],minx);
		maxx=max(maxx,a[i]);
	} 
	int h=m;
	for(int i=minx;i<=maxx;i++){
		m=h;
		ans=max(ans,suan(i));
	}
	printf("%lld",ans);
	return 0;
} 
