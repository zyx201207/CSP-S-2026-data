#include<bits/stdc++.h>
#define maxn 500005
#define lll long long
using namespace std;
lll n,m;
lll a[maxn];
lll b[maxn];
lll bal;
lll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld" ,&n ,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld" ,&a[i]);
	}

	if(n==1){
		cout<<"1"<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	
	for(int i=1;i<=n;i++){
		if(b[i]+m>=a[i]*i){
			ans=i;
		}
	}
	printf("%lld",ans);	
	return 0;
}

