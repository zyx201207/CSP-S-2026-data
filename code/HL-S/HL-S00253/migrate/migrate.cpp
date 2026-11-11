#include<iostream>
#include<algorithm>
using namespace std;
int a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(d<a[2]-a[1]){
			cout<<0<<endl;
			continue;
		}
		cout<<d<<endl;
	}
	return 0;
}
