#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int c,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int sum=n%d;
		cout<<sum+1<<endl;
	}
	
	
	return 0;
}
