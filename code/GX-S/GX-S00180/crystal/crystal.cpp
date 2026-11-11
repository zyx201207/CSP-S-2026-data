#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e5+5;
ll a[MAXN],pre[MAXN];
ll n,m;
int c=0,c2=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		if(a[i]!=a[i-1]&&i!=1){
			c=1;
		}
	}
	if(c==0){
		cout<<n<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	pre[0]=0;
	for(int i=1;i<=n;++i){
		pre[i]=pre[i-1]+a[i];
	}
	ll maxx=1LL;
	for(int i=2;i<=n;++i){
		for(int j=i;j>=1;--j){
			if((i-j+1)*a[i]-(pre[i]-pre[j-1])>m){
				//maxx=max((i-j+1)*1LL,maxx*1LL);
				break;
			}
			else{
				maxx=max((i-j+1)*1LL,maxx*1LL);
			}
		}
	}
	cout<<maxx<<endl;
	return 0;
}
//daihuilaiyouhua
