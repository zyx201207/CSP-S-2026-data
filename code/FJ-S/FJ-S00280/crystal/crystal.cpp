#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(m==0){
		long long ans=0,cnt=0;
		for(int i=1;i<=n-1;i++){
			if(a[i]==a[i+1]) cnt++;
			else{
				ans=max(ans,cnt);
				cnt=0;
			}
		}
		printf("%lld",ans+1);
		return 0;
	}
	sort(a+1,a+1+n);
	long long ans=0;
	for(int i=2;i<=n;i++){
		long long cnt=0,t=1;
		for(int j=1;j<=n;j++){
			if(a[j]<a[i]){
				cnt+=a[i]-a[j];
				t++;
			}
		}
		if(cnt<=m){
			long long x=i+1;
			while(a[x]==a[i]){
				t++;
				x++;
			}
			ans=max(ans,t);
		}
		else break;
	}
	printf("%lld",ans);
	return 0;
}
