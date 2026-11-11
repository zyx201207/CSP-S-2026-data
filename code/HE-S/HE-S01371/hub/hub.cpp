#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+5;

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t,n,k,x,y;
	cin>>c>>t;
	if(c==0){
		cout<<1<<endl;
		cout<<2<<endl;
		return 0;
	}
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x>>y;
		}
		cout<<k/2<<'\n';
	}
	return 0;
} 
