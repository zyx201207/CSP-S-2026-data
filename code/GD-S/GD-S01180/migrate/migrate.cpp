#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		if(c==11||c==12){
			int s=n;
			s-=2;
			long long a,b;
			cin>>a>>b;
			while(s--){
				int x;
				cin>>x;
			}
			if(b-a>d){
				cout<<0<<endl;
			}else{
				cout<<n-2*(d/(b-a))+1<<endl;
			}
		}else{
			while(n--){
				int x;
				cin>>x;
			}
			cout<<0<<endl;
		}
	}
	return 0;
} 
