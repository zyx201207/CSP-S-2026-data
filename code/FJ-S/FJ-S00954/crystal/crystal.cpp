#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[500005],c[500005],ans[500005];
int cnt=0,st,kk=1;
int ll,rr,mm,maxx,len,lef;
int ji;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	mm=m,lef=1,len=1;
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i = 2;i<=n;i++){
		if(mm>=(i-1)*b[i]){
			mm-=(i-1)*b[i];
			len++;
			st=i;
			ans[i]=i;
		}
		else break;
	}
	for(int i = st+1;i<=n;i++){
		//1、可以继续加
		if(b[i]*len<=mm){
			mm-=b[i]*len;
			len++;
			ans[i]=len;
			continue;
		} 
		//2、和上一个相等
		if(a[i]==a[i-1]){
			len++;
			ans[i]=len;
			continue;
		} 
		//3、和上一个差太多
		if(b[i]>m){
			len=1;
			ans[i]=len;
			mm=m;
			lef=i;
			continue;
		} 
		//按顺序加
		ll=a[i-1]-a[lef];
		len--;
		lef++;
		mm+=ll;
		while(mm<len*b[i]){
			ll=a[i-1]-a[lef];
			mm+=ll;
			len--;
			lef++;
		}
		len++;
		mm-=len*b[i];
		ans[i]=len;
	}
	//统计
	for(int i = 1;i<=n;i++){
		maxx=max(maxx,ans[i]);
	} 
	printf("%lld",maxx);
	return 0;
}
/*
14 12
-4 -3 2 6 7 8 9 10 51 51 51 52 55 58
*/
