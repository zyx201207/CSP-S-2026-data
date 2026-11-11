//正解是DP 01背包,贪心也许也可以
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll,ll>;
const ll N = 2*1e5;
ll n,m;
struct number{
	ll on=0;
	ll val=0;
}nums[N];
ll OneNumberInBinary(ll x){
    ll ret=0;
    while(x){
        ret+=(x&1);
        x/=2;
    }return ret;
}
bool mcmp(number a,number b){
	return a.on>=b.on;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	#ifndef LOACL_RUN
	ifstream fi("and.in");
	ofstream fo("and.out");
	#define cout fo
	#define cin fi
	#endif
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll a;
        cin>>a;
		nums[i].val=a;
		nums[i].on=OneNumberInBinary(a);
    }sort(&nums[1],&nums[n+1],mcmp);
	ll ans=nums[1].val;
	for(int i=1;i<=m;i++){
		ans&=nums[i].val;
	}cout<<ans;
	return 0;
}
