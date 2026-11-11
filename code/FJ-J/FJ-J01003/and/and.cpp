#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	long long ans=0;
	long long cnt=0;
	sort(a+1,a+n+1);
	if(m==2){
		for(int i=n;i>=1;i--){
		ans=max(ans,a[i]&a[i-1]);
		}
	    printf("%lld",ans);
		return 0;
	}
	
	else{
		for(int i=n;i>=1;i--){
		    for(int j=1;j<m;j++){
		    	cnt=a[i]&a[i-j];
			}
			ans=max(ans,cnt);
		}
		printf("%lld",ans);
	}
	return 0;
}
