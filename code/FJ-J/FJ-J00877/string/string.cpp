#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans,d,p[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	d=n;
	for(long long i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(long long i=1;i<n;i++){
		if(d<=i)break;
		for(long long j=d;j>i;j--){
			if(c[i]==c[j]){
				if(a[i]>a[j]){
					a[i]-=a[j];
					a[j]=0;
					d--;
					continue;
				}
				if(a[i]<=a[j]){
					a[j]-=a[i];
					a[i]=0;
					break;
				}
			}
			if(a[i]>a[j]){
				ans+=a[j];
				d--;
				a[i]-=a[j];
				a[j]=0;
				continue;
			}
			ans+=a[i];
			a[j]-=a[i];
			a[i]=0;
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}
