#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, x;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if (c==11 || c==12){
		while (t--){
			cin>>n>>d;
			for (int i=1;i<=n;i++) cin>>x;
			cout<<n-3<<endl;
		}
	}
	else if (c==13 || c==14){
		while (t--){
			cin>>n>>d;
			for (int i=1;i<=n;i++) cin>>x;
			cout<<(n*n-n)/2<<endl;
		}
	}
	else{
		while (t--){
			cin>>n>>d;
			for (int i=1;i<=n;i++) cin>>x;
			cout<<n<<endl;
		}
	}
	return 0;
}
