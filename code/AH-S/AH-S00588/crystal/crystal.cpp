#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ikun="woshixiaohezi";//I'm true ikun
const int maxn=1e6+10;
ll n,m,a[maxn],pos=-1e9,sum,x;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-x-1);
		while(sum>m){
			x++;
			sum=sum-a[i]+a[x];
		}
		pos=max(pos,i-x);
	}
	cout<<pos;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
    return 0;
}
