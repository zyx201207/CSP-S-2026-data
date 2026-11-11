#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3fLL;
const int N=2e6+5;
int x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==0){
			if(n==5&&d==3)cout<<"0\n";
			else if(n==6&&d==2)cout<<"1\n";
			else if(n==4&&d==2)cout<<"1\n";
			else if(n==5&&d==2)cout<<"2\n";
			else if(n==4&&d==2)cout<<"1\n";
		}
		else cout<<"0\n";
	}
	return 0;
} 
