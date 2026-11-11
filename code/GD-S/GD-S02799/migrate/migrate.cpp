#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
ll c,T;
ll n,d,x[2000010],ans;
bool check(ll i,ll x,ll j){
	return x-i<=d&&j-x<=d;
}
void solve1(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++)cin>>x[i];
	ans=0;
	x[0]=-1e18-1;
	for(ll i=1;i<=n;i++){
		for(ll j=i+2,pos1,pos2;j<=n;j++){
			pos1=upper_bound(x+1,x+n+1,x[i]+d)-x-1,pos2=lower_bound(x+1,x+n+1,x[j]-d)-x;
			if(pos1<pos2)break;
			if(pos1==1+pos2&&pos2>=i&&pos1<=j&&check(x[i],pos1,x[j])&&check(x[i],pos2,x[j])){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	for(ll i=1;i<=n;i++)x[i]=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>T;
	while(T--)solve1();
	return 0;
}
