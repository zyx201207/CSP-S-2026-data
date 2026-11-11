#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,j = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i = m;i >= 0;){
		i -= abs(a[j+1]-a[j])*ans;
		j++;
		ans++;
	}
	cout<<ans;
	return 0;
}
