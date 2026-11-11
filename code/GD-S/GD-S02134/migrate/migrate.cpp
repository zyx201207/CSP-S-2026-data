#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
mt19937_64 rng(time(0));
ll c,t,n,d;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		n=n/d;
		cout<<(rng()%n+1);
	}
	
	
	return 0;
}


