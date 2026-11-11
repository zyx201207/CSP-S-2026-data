#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
long long a[N+1];
long long diff=-1;
int n;
bool specialA(){
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) return false;
	}
	diff=a[2]-a[1];
	return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(specialA()){
			if(d>=2*diff&&d<3*diff){
				cout<<n-3<<endl;
				cerr<<n-3<<endl;
			}
			else{
				cout<<"0"<<endl;
				cerr<<"0"<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
