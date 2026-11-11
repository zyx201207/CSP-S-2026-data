#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=500005;
int n,m,ts,t,cnt,res=0;
int a[N];

signed main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	for(int i=n;i>=res;i--){
		cnt=ts=0;
		if(a[i]-a[i-res]>m){
			continue;
		} 
		for(int j=i;j>=1;j--){
			t=a[i]-a[j];
			if(t+ts>m){
				break;
			}
			cnt++;
			ts+=t;
//			printf("%d %d\n",a[j],t);
		}
		res=max(res,cnt);
//		printf("%d %d\n\n",ts,res);
	}
	
	printf("%lld",res);
	
	return 0;
}

