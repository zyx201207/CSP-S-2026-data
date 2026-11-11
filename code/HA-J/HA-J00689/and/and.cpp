#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=2e5+10;
ll n,m,a[N],maxx=-6e10;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll s;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			s=a[i]&a[j];
			//cout<<a[i]<<" "<<a[j]<<endl;
			maxx=max(maxx,s);
		}
	}
	cout<<maxx<<endl;
	return 0;
}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
