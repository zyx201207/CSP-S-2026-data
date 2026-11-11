#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,k,T,n;
vector<pair<int,int> >g[1000005];
bool check(int x){
	for(auto v:g){
		if(check(v)){
			return 0;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n==k) cout<<0<<"\n";
		else if(n-k==3) cout<<1<<"\n";
		else{
			int l=1,r=n;
			while(l<r){
				int mid=(r-l)/2+l;
				if(check(mid)){
					l=mid+1;
				}else{
					r=mid;
				}
			}
			cout<<l<<"\n";
		}
	}
	return 0;
}
