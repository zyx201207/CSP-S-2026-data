#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
const ll N=5e5+7;
ll n,m,s=-1,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		ll t=0,b[N],sum=0;
		for(ll j=i-1;j>=1;j--){
			b[i]=(a[i]-a[j]);
			sort(b+1,b+i+1);
			if(sum>m){
				break;
			}
			t++;
		}
		s=max(s,t);
	}
	cout<<s;
	return 0;
}
/*
  5 8
 -3 -1 2 2 7

 5 5
 1 2 4 8 9
*/

