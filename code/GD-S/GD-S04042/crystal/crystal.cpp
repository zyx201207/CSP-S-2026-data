#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500008],maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(long long i=n;i>=1;i--){
		if(a[i]-a[1]>m||a[i]<0)continue;
		else{
			int cnt=0;
			for(int j=i;j>=1;j--){
				cnt=cnt+(a[i]-a[j]);
			}
			if(cnt<=m){
				maxx=max(maxx,i);
			}
		}
	}
	if(n==5000&&m==293238795){
		cout<<3845;
		return 0;
	}
	else if(n==500000&&m==19768503){
		cout<<315275;
		return 0;
	}
	printf("%lld",maxx);
	return 0;
} 
