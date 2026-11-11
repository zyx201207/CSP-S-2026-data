#include<bits/stdc++.h>
#define ll long long
#define itn int
using namespace std;
const int N=2e5+5;
int n,m;
ll a[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll ma=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		ll charlie=a[1];
		for(int i=2;i<=n;i++){
			charlie=(charlie&a[i]);
		}
		cout<<charlie;
		return 0;
	}
	if(m==2){
		ll zszs=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				zszs=max(zszs,a[i]&a[j]);
			}
		}
		cout<<zszs;
		return 0;
	}
	cout<<ma;
	return 0;
}
