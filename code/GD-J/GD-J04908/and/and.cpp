#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	ll z=0;
	z=a[n-1]&a[n-2];
	if(m==1) cout<<a[n-1];
	if(m>2){
		for(int j=2,k=1;j<m;j++,k++){
			z=z&a[n-2-k];
		}
	}
	cout<<z;
	return 0;
} 
