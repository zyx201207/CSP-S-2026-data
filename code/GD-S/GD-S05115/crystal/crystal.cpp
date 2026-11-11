#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,b[N],z,s,j;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	z=m;
	for(ll i=1;i<=n;i++){
		z-=(b[i]-b[i-1])*s;
		if(z<0) break;
		s+=1;
	}
	cout<<s;
}
