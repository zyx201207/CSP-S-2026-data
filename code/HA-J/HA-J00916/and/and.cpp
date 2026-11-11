#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,sum=-0x3fffffff;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ll a;
		cin>>a;
		if(a>sum) sum=a;
	}
	cout<<sum;
	return 0;
}
