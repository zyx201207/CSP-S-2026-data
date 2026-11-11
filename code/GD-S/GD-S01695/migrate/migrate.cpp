#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e6+9;
int c,t,x[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(2*(x[2]-x[1])<=d&&3*(x[2]-x[1])>d){
			cout<<n-2<<"\n";
		}
		else{
			cout<<0<<"\n";
		}
	}
	
	return 0;
} 
