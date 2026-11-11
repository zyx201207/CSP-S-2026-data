#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],ans=0;

long long count(int x){
	long long t=0;
	for(int i=1+x;i<=n;i++){
		t+=(a[i]-a[i-1])*(i-1);
		if(t>m){
			return i-x;
		}
	}
	return n-x+1;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long j=count(i);
		if(ans>n-i+1){
			break;
		}
		ans=max(ans,j);
	}
	printf("%lld",ans);
    return 0;
}
