#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,ans=1;
long long a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==0){
			b[i]=b[i-1]+1;
		}else{
			b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		}
	}
	for(int i=2;i<=n;i++){
		int q=lower_bound(b+1,b+n+1,b[i]-m)-b;
		if(q==-1) q=0;
		if(i-q+1>ans) {
		    ans=i-q+1;
		}
	}
	printf("%lld",ans);
	return 0;
}
