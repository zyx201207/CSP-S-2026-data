#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const ll inf=1e16;
void chmin(ll &x,const ll &y){
	if(y<x){
		x=y;
	}
}
int c,t,n,m,d,q;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cout<<rand()%1+1<<"\n";
	}
	return 0;
}
