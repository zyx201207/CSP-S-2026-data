//GZ-S00218 ³ÂÍþºÀ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll c,t,n,d,a[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll i=1,j=1,lj=1,li=1;
	while(a[j+1]-a[i]<=d) j++;
	lj=j,li=i;
	ll sum=0;
	while(j<n){
		while(i+1<=j && a[j+1]-a[i]>d && j+1<=n){
			i++;
		}
		while(a[j+1]-a[i]<=d && j+1<=n){
			j++;
		}
		if(i+1==lj && j>lj){
			sum+=(i-li)*(j-lj);
			li=i,lj=j;
		}
		if(i==j) i++,j++;
	}
	cout<<sum<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
