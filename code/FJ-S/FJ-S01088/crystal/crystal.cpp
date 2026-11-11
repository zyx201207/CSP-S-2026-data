#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N];
ll cst[N];
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ans=1;
	for(int l=1,r=2;r<=n;r++){
		cst[r]=cst[r-1]+(a[r]-a[r-1])*(r-l);
		while(cst[r]>m){
			cst[r]-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,(ll)r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
