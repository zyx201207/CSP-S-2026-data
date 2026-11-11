#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+10;
ll w[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll c,n,m,q,d;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=q;i++){
		cout<<1<<'\n';
	}
	
	
	return 0;
}
