#include<bits/stdc++.h> 
using namespace std;
long long a[2000005],d;
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	int A,T,n;
	cin>>A>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		long long c=d/(a[2]-a[1]);
		if(d<2)cout<<"0\n";
		else cout<<n-2*d+1;
	}return 0;
}
