#include <bits/stdc++.h>
using namespace std;
int aa[200005];
long long ans;
char zc[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>aa[i]>>zc[i];
		if(zc[i]!=zc[i-1])t++;
	}
	if(t==1){
		printf("0");
		return 0;
	}
	else if(t==n+1){
		for(int i=1;i<=n;i++){
			ans=ans+aa[i];
		}
		if(ans%2==1)printf("%lld",(ans-1)/2);
		else printf("%lld",ans/2);
	}
	return 0;
}
