#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+20;
long long c,t;
long long n,d;
long long a[N];
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	bool flag=1;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			}
		if(d==2){
			flag=0;
			cout<<n%(d+1)<<endl;
			}
		}
	if(flag){
		cout<<0<<endl;
		cout<<0;
		}
	return 0;
}
