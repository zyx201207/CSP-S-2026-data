#include<iostream>
#include<cmath>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			ans+=x;
		}
		cout<<abs(ans)<<'\n';
	}
	return 0;
} 
