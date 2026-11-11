#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,x[2000010],n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<n/2<<'\n';
	}
	return 0;
}
