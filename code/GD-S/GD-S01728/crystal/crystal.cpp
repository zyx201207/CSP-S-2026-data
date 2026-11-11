#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int q=a[1];
	ll b_s,c_s;
	ll ma=0;
	for(int i=1;i<=n;i++){
		if(a[i]==q){
			b_s++;
		}
	}
	if(a[b_s-1]+1==a[b_s]&&b_s-1<=m) b_s+=1;
	printf("%lld",b_s-1);
	return 0;
}
