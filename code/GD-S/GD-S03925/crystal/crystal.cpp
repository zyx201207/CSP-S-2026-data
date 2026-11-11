#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long m[N];//每一项的差 
long long s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,k;
	scanf("%lld%lld",&n,&k);
	long long cnt=0;
	bool f=0,c=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>3){
			if(a[i]-a[i-1]==a[i-1]-a[i-2])f=1;
			else{
				f=0;
				c=1;
			}
		}
		if(a[i]==i)cnt++;
	}
	if(cnt==n){
		printf("%lld",k+1);
		return 0;
	}
	if(!c&&f){
		printf("%lld",k/(a[3]-a[2])+1);
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		m[i-1]=a[i]-a[i-1];
		s[i-1]=s[i-2]+m[i-1];
	}
	long long ans=0;
	for(int l=1;l<n;l++){
		for(int r=l+1;r<n;r++){
			if(s[r]-s[l-1]<=k)ans=max(ans,(long long)(r-l+2));
		}
	}
	printf("%lld",ans);
	return 0;
}
