#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	int x[200]
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int i=0;i<min(n,200);i++){
			cin>>x[i];
		}if(d>=2*(x[1]-x[0])&&d<3*(x[1]-x[0])&&n>=4){
			cout<<n-3;
		}else{
			cout<<0;
		}
	}
	return 0;
}
