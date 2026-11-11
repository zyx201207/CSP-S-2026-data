#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int MN=5e5+50;
ll f[MN];
struct p{
	int cha,bh;
};
p sum[MN];
ll s[MN];
ll sum_s=0;
bool cmp(p x,p y){
	return x.cha<y.cha;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n;ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		sum_s+=f[i];
	}
	sort(f+1,f+1+n);
	for(int i=n;i>=1;i--){
		if((sum_s+m)/i>=f[i]){
			cout<<i;
			return 0;
		}
		if((sum_s+m)/i<f[i]){
			sum_s-=f[i];
			continue;
		}
	}
	return 0;
}
