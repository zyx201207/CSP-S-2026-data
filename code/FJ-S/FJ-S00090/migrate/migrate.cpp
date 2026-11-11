#include <bits/stdc++.h>
using namespace std;
int c,T;
int n;
long long d;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(c>=11&&c<=12){
			if(d<=a[2]-a[1]) cout<<0<<endl;
		}
	}

	return 0;
}

