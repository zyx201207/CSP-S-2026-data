#include "bits/stdc++.h"
using namespace std;
typedef long long ll1;
const int N=1e6+5;
ll1 a[N],m;
int Ans=0,n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//fun
	//增加 1，不是增减 1
	//nmsl
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int l=1;
	for(int i=1;i<=n;i++){
		if(i!=1)m-=1ll*(i-l)*(a[i]-a[i-1]);
		while(m<0)m+=(a[i]-a[l++]);
		Ans=max(Ans,i-l+1);
	}
	printf("%d\n",Ans);
	return 0;
}