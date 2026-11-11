#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,p;
ll a[200010];
struct Node{
	ll ting;
	ll zhan;
	ll j[1010];
}node[10100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(ll i=1;i<=m;i++)cin>>node[i].ting;
	for(ll i=1;i<=n;i++){
		cin>>node[i].j[i]>>node[i].zhan;
	}
	while(p--){
		ll st,en,sum=0;
		cin>>st>>en;
		for(ll i=1;i<=n;i++){
			for(auto x:node[i].j){
				if(x==en){
					sum+=node[st].ting+node[x].zhan;
					cout<<sum+node[en].ting<<endl;
					break;
				}
				else{
					for(auto k:node[x].j){
						sum+=node[k].zhan;
						cout<<sum+node[en].ting<<endl;
						break;
					}
				}
			}	
		}
		
	}
	return 0;
}
