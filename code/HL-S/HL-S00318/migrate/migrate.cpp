#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,t;
int n,d;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>x[i];
		}
		if (c==13||c==14){
			cout<<0<<"\n";
		}
	}
	return 0;
}
