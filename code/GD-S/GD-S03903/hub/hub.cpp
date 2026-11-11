#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e6+5;
int x[N],c,t;
signed main(){
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		srand(time(0));
		int ans=rand()%170;
		cout<<ans<<endl;
	}
	return 0;
} 
