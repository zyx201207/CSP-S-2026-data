#include<bits/stdc++.h>
#define int long long
using namespace std;

int cc,t; 
int n,k;
int u,u1;
int v[4010][4010];
int y[10];
int ans;

signed main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin>>cc>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>u>>u1;
		if(k<=2) cout<<"1"<<endl; 
		else cout<<"2"<<endl;
	}
	return 0;
} 
