#include <bits/stdc++.h>
using namespace std;
long long n,d,c,t,cnt,minn=2e9,pos;
long long a[5000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		cnt=0;
		scanf("%lld %lld",&n,&d);
		pos=n;
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]-d>a[i-1])pos=i-1;
		}
		for(int i=1;i<=pos-2;i++){
			int cnt1=0;
			for(int j=pos;j>=i+3;j--){
				cnt1=0;
				for(int k=i+1;k<j;k++){
					if(abs(a[j]-a[k])<=d&&abs(a[k]-a[i])<=d&&abs(a[j]-a[i])<minn){
						minn=abs(a[j]-a[i]);
						break;
					}
				}
				for(int k=i+1;k<j;k++){
					if(abs(a[j]-a[k])<=d&&abs(a[k]-a[i])<=d&&abs(a[j]-a[i])==minn){
						cnt1++;
					}
				}
				if(cnt1==2)cnt++;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
