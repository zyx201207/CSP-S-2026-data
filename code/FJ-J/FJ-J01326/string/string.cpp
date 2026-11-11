#include<bits/stdc++.h>
using namespace std;
long long n,i,a[200005],ans,b;
char c[200005],o;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	for(i=1;i<=n/2;i++){
		if(a[i]<=0){
			a[i+1]+=a[i];
			if(c[i]==o) ans-=b;
		}
		else if(c[i]!=c[n+1-i]){
			if(a[i]>a[n+1-i]){
				o=c[i];
				b=a[i]-a[n+1-i];
			    a[n+1-i-1]=-b+a[n+1-i];
				if(c[i]!=c[n+1-i-1]) ans+=a[i];
				else ans+=a[n+1-i];
			}else{
				o=c[n+1-i-1];
				b=a[n+1-i]-a[i+1];
				a[i+1]=-b+a[i];
				if(c[i]!=c[n+1-i-1]) ans+=a[n+1-i];
				else ans+=a[i];
			}
		}else{
			if(a[i]>a[n+1-i]) a[n+1-i-1]=a[n+1-i-1]-a[i]+a[n+1-i];
			else a[i+1]=a[i+1]-a[n+1-i]+a[i];
		}
	}
	printf("%lld",ans);
	return 0;
}