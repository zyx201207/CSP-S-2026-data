#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll C,T,n,d;
int a[N],cha[N];//cha£º1~iµÄ¾àÀë 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(cha,0,sizeof(cha));
		cha[1]=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			cha[i]=a[i]-a[1];
		}
		sort(a+1,a+n+1);
		if(n%2==1){
			cout<<n/2;
		}else{
			cout<<n/2-1;
		}
	}
	return 0;
}
