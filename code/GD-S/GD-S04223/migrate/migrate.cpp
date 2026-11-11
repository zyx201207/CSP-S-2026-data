#include<iostream>
using namespace std;
long long c,t,n,d,tmp;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
    	cin>>n>>d;
    	for(int i=0;i<n;i++) cin>>tmp;
    	cout<<(n/d)+(n%d)-1<<'\n';
	}
    
    

	return 0;
}
