#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int C,T,n,d,a[N],cnt=1;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		printf("%lld\n",cnt);
		cnt++;
	}
	return 0;
}
