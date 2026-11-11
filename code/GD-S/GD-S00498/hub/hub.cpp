#include<bits/stdc++.h>
using namespace std;
#define int long long
#define push_back pb
#define first fi
#define second se
int c,t,n,a;
signed main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	//system("fc hub.ans hub.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a>>a;
		cout<<(n-1)/4;
	}
	return 0;
}
