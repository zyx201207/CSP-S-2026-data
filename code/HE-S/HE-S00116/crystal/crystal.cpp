#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
int n,m,a[N],ans1,ans2,ans;
int sum,mid;
bool flag1=true,flag2=true;
int32_t main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for (int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		if(a[i]!=i) {
			flag1=false;
		}
	}
	int temp=a[2]-a[1];
	for(int i=3;i<=n;i++) {
		if(a[i]-a[i-1]!=temp) {
			flag2=false;
		}
	}
	if(flag1) {
		for(int i=n-1;i>=1;i--) {
			m-=(a[n]-a[i]);
			if(m>0) ans++;
			else break;
		}
		printf("%lld",ans);
		return 0;
	}
	if(flag2) {
		for(int i=n-1;i>=1;i--) {
			m-=temp;
			if(m>0) ans++;
			else break;
		}
		printf("%lld",ans);
		return 0;
	}
	sort(a+1,a+n+1);
	if(n%2!=0) {
		mid=a[n/2+1];
		int start=n/2;
		for (int i=start; i>=1; i--) {
			if(a[i]>mid) break;
			sum+=mid-a[i];
			if(sum<=m) ans1++;
			else break;
		}
		sum=0;
		for (int i=start+1; i<=n; i++) {
			if(a[i]>mid) break;
			sum+=mid-a[i];
			if(sum<=m) ans2++;
			else break;
		}
		for(int i=1; i<=n; i++) {
			if(a[i]=a[i+1]) {
				ans++;
			}
		}
	} else {
		mid=ceil((a[n/2]+a[n/2+1])/2.0);
		int start1=n/2,start2=n/2+1;
		for (int i=start1; i>=1; i--) {
			if(a[i]>mid) break;
			sum+=mid-a[i];
			if(sum<=m) ans1++;
			else break;
		}
		sum=0;
		for(int i=start2; i<=n; i++) {
			if(a[i]>mid) break;
			sum+=mid-a[i];
			if(sum<=m) ans2++;
			else break;
		}
	}
	printf("%lld",ans);
	return 0;
}//bahaha xie le 80 duo hang tiao le 1 ge duo xiao shi
 //jie guo da yang li yi ge mei guo gao xing si wo le ba ha ha 
