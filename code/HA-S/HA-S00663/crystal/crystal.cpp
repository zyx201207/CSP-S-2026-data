#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,pos,dif=1,maxn=0;
ll a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	ll l=1,r=n;
	while(sum[r]-sum[l-1]>m){
		if(sum[r]>a[r]-a[l]){
			r--;
		}
		else l++;
	}
	//cerr<<l<<" "<<r<<"\n";
 	cout<<r-l+1;
	return 0;
}