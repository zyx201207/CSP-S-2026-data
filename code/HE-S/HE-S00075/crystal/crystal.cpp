#include<bits/stdc++.h>
#include<set>
#define ll long long
#define up(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define dn(i,a,b,c) for(ll i=a;i>=b;i-=c)

using namespace std;
const ll N=5e5+10;
ll n,m;
ll a[N];
ll num=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	up(i,1,n,1)cin>>a[i];
	sort(a+1,a+n+1);
	num=0;
	up(i,1,n,1){
		num+=(i-1)*(a[i]-a[i-1]);
		if(num>m){
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	return 0;
}
