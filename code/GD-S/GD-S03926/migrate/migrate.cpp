#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _,t;
	cin>>_>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			int tmp;
			cin>>tmp;
		}
		cout<<max(0,a-(2*b-1))<<'\n';
	}
	
}
