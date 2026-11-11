#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
const int N=2e6+10;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n*(n-1)/2<<'\n';
	}
	return 0;
}
