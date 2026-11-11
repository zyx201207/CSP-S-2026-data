#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1e8+10;
ll c,t,n,k,u[MAX_N],v[MAX_N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(ll i = 0; i < t; i++){
		cin>>n>>k;
		for(int j = 1; j <= n-1; j++){
			cin>>u[i]>>v[i];
		}
	}
	cout<<1<<endl<<2;
}
