#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+100;
ll n,m,ans,l,r;
ll ar[N],cr[N];
ll t[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	sort(ar+1,ar+n+1);
	for(int i=n;i>=1;i--){
		ll l=0;
		ll k=m;
		for(int j=i;j>=1;j--){
			if(k>=(ar[i]-ar[j])){
				l++;
				k-=(ar[i]-ar[j]);
			}
		}ans=max(ans,l);
	}
	cout<<ans;
	return 0;
}

