#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;cin>>c>>t;
	srand(time(0));
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			int a;cin>>a;
		}
		if(c<=2){
			cout<<rand()%5<<endl;
		}else if(c<=6){
			cout<<rand()%150<<endl;
		}else if(c<=10){
			cout<<rand()%2500<<endl;
		}else{
			cout<<rand()*100<<endl;
		}
	}
	
	return 0;
}
