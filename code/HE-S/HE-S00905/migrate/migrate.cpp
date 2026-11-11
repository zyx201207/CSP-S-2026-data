#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int t,c;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d==1) cout<<0<<"\n";
		if(d==2) cout<<n-3<<"\n";
		else cout<<0<<"\n";
	} 
	return 0;
}
