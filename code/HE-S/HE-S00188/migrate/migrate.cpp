#include<bits/stdc++.h>
using namespace std;
int n,c,t;
long long d,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int z=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		long long e=x[2]-x[1],w=e+d,a=1;
		while(x[a]+w<=x[n]){
			if(x[a]+w<=x[n]) z++;
			a++;
		}
		cout<<z;
	}
	return 0;
}
