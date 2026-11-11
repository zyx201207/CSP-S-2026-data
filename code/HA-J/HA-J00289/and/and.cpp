#include <iostream>
#include <cstdio>
#define ll long long
#define H <<' '<<
using namespace std;
ll n,m,a[200005],ans;
bool b[200005][33],d[2000005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("and.in","r",stdin);
//	freopen("and/and5.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		for(ll j=0;j<=30;j++){
			b[i][j]=a[i]&(1<<j);
		}
	}
	for(ll j=30;j>=0;j--){
		ll s=0;
		for(ll i=1;i<=n;i++){
			if(!d[i]){
				s+=b[i][j];
			}
		}
		if(s>=m){
			ans+=1<<j;
			for(ll i=1;i<=n;i++){
				if(!d[i]&&b[i][j]==0){
					d[i]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
// 100
