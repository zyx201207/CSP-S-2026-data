#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll c,t,n,m,d; 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>t;
	while(t--){
		int tt=min(n,m);
		cout<<(rng()%tt+1);
	}
	
	
	return 0;
}
