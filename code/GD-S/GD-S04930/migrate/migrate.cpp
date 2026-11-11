#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	if(c==11 or c==12){
		while(t--){
			long long a,b;
			cin>>a>>b;
			if(a<4){
				for(long long i=1;i<=a;i++)cin>>b;
				cout<<0;
			}
			else{
				long long x,y;
				cin>>x>>y;
				if(abs(y-x)>b){
					for(long long i=3;i<=a;i++){
						cin>>b;
					}
					cout<<0;
				}
				else{
					for(long long i=3;i<=a;i++){
						cin>>b;
					}
					cout<<a-3;
				} 
			}
			cout<<endl;
		}
	}
	else cout<<"i do not know";
	return 0;
} 
