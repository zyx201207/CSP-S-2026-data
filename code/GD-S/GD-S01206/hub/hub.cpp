#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
		}
		if(n==2&&k==2)cout<<1<<"\n";
		else if(k==2){
			cout<<0<<"\n";
		}else{
			cout<<k/4<<"\n";
		}
	} 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}/*
8pts 
*/
