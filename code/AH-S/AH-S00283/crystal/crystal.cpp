#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[510000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long mm=0,head=1,cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		mm+=cnt*(a[i]-a[i-1]);
		cnt++;
		if(mm>m){
			mm-=a[i]-a[head];
			head++;
			cnt--;
		}
		ans=max(ans,cnt);
		
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
