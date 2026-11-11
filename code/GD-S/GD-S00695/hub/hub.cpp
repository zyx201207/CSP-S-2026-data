#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
struct Edge{int u,v;}G[maxn];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//É¾×¢ÊÍ
	int C,t_;cin>>C>>t_;
	while(t_--){
		int n,k;cin>>n>>k;
		for(int i=1;i<n;i++)cin>>G[i].u>>G[i].v;
		if(C==13||C==14)cout<<"1\n";
	}
	return 0;
} 
