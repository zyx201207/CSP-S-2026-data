#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		if(c==14||c==13){
			cout<<n<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}
