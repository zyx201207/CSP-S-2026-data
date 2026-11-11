#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string st;
ll n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<ll>());
	if(m==1){
		cout<<a[0];
		return 0;
	}
	if(m==2){
		ll x=-1;
		for(int i=0;i<n-1;i++){
			for(int j=1;j<n;j++){
				x=max(x,a[i]&a[j]);
			}
		}
		cout<<x;
		return 0;
	}
	cout<<a[0];
	return 0;
}
