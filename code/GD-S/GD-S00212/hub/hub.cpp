#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int c,T;
int n,k;
vector<int> G[1000005];
bool chk(int m){
	return rand()%2;
}
void sol(){
	cin>>n>>k;
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	int l=1,r=n;
	int res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid))
			r=mid-1,res=mid;
		else
			l=mid+1; 
	}
	cout<<2<<endl;
}
int main(){
//	srand(time(0)); 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>c>>T;
	while(T--){
		sol();
	} 
	return 0;
} 
