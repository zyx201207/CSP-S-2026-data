//GZ-J00025 贵阳市白云区华师一学校 吴星汉 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],num[200010][40],ans;
vector<ll> vec,nvec;
stack<ll> sta;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;n>=i;i++){
		scanf("%lld",&a[i]);
		ll pos=0;
		while(a[i]){
			num[i][pos]=a[i]%2;
			a[i]/=2;
			pos++;
		}
	}
	for(ll i=30;i>=0;i--){
		for(ll j=1;n>=j;j++){
			if(num[j][i]==1) vec.push_back(j);
		}
		if(vec.size()>=m) break;
		vec.clear();
	}
	for(ll i=30;i>=0;i--){
		for(ll &j:vec){
			if(num[j][i]==1){
				nvec.push_back(j);
			}
		}
		if(nvec.size()>=m){
			vec=nvec;
			ans+=1<<i;
		}
		nvec.clear();
	}
	printf("%lld",ans);
	return 0;
}
