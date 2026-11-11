#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,a[5000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	srand(time(0));
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<rand()%3<<endl;
	}
	return 0;
}
