#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int a[1000000];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<(a[n]+a[1])/d<<endl;
	}
	return 0;
}
