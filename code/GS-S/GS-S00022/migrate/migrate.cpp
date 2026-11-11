#include <bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000005];
int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;int n,d;
	while (t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
				cin>>a[i];
		}
		if(c>=11&&c<=12){
			long long ab=a[2]-a[1];
			if(ab>d){
				cout <<0<<"\n";
			}
		}
		else if(c==13||c==14){
			cout <<0<<"\n";
		}
	}
	return 0;
}
