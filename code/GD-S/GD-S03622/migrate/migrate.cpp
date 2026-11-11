#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(d%2==0){
			cout<<n-d-1<<endl;
		}
		else if(n%d==0){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}
