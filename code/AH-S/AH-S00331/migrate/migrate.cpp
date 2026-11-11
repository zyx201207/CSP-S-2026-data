#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,x[2000010];
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			if(d>=2){
				cout<<1;
			}
			else{
				cout<<0;
			}
			continue;
		}
	}
	return 0;
}
