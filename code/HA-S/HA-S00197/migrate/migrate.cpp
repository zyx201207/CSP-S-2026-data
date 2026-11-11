#include<bits/stdc++.h>
using namespace std;
int a[2000006];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		cout<<(n-1)/2<<"\n";
	}
	return 0;
}
