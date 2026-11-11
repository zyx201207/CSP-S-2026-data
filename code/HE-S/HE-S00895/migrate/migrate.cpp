#include<bits/stdc++.h>
using namespace std;
string x;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,a;
	cin>>c>>t;

	for(int i=0; i<t; i++) {
		cin>>n>>d;
		for(int j=0; j<(n+1)/d; j++) {
		cin>>x[a];
		if(n%d!=0) {
			cout<<(n-1)/d;
		} else {
			cout<<(n+1)/d;
		}
	}
	}




	fclose(stdin);
	fclose(stdout);
	return 0;
}





















