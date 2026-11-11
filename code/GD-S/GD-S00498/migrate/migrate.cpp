#include<bits/stdc++.h>
using namespace std;
#define int long long
#define push_back pb
#define first fi
#define second se
int c,t,n,d,x[500005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//system("fc migrate.ans migrate.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d>=x[2]-x[1]&&d<2*(x[2]-x[1])){
			cout<<n-2;
		}else cout<<0;
	}
	return 0;
}
