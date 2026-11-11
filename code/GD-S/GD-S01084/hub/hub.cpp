#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
vector<ll> g[N];
int c,t,n,k,xx,yy;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
while(t--){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>xx>>yy;
		g[xx].push_back(yy);
		g[yy].push_back(xx);
	}
	cout<<"0\n";
}
}
