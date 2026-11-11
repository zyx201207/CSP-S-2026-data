#include <bits/stdc++.h>
using namespace std;


int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t; 
	while(t--){
		long long n,d;
		cin>>n>>d;
		vector<long long> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(d>=a[n-1]-a[0]){
			cout<<0;
			continue;
		}
		if(c==11||c==12){
			int z=a[1]-a[0];
			if(d%z==0){
				cout<<0<<endl;
				continue;
			}else{
				cout<<n-d/z-d/z+1<<endl;
			}
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
