#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		char t;
		scanf("%lld%c%c",&a[i],&t,&c[i]);
	}
	long long cnt=n;
	for(int i=1;i<=n;i++){
		if(a[i]==0) break;
		for(int j=cnt;j>0;j--){
			if(c[i]!=c[j]){
				if(a[j]>=a[i]){
					a[j]-=a[i];
					ans+=a[i];
					a[i]=0;
					break;
				}else{
					ans+=a[j];
					a[i]-=a[j];
					cnt--;
					a[j]=0;
				}
			}else{
				if(a[j]>=a[i]){
					a[j]-=a[i];
					a[i]=0;
					break;
				}else{
					a[i]-=a[j];
					cnt--;
					a[j]=0;
				}	
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
