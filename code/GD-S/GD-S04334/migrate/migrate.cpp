#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,a[N];
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d<abs(a[1])+abs(a[n])){
			if(a[1]<=0)
		cout<<(a[1]+a[n])/2<<endl;
		else{
			cout<<(a[n]-a[1])/2<<endl;
		}
	}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}
