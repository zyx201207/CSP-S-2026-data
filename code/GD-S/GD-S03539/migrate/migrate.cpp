#include<bits/stdc++.h>
using namespace std;
long long c,t,a[100000]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int k=abs(a[1]-a[2]);
		int t=(d+k-1)/k;
		cout<<t-1<<endl;
	}
	return 0;
}
