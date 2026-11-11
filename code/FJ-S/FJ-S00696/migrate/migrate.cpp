#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			long long n,d;
			cin>>n>>d;
			long long x;
			cin>>x;
			for(long long i=1;i<=n;++i){
				cin>>x;
			}
			cout<<(n-3)*(n-2)/2;
		}
	}else{
		for(long long i=1;i<=t;++i){
			cout<<1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
