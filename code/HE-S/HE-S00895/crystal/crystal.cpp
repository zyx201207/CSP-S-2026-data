#include<bits/stdc++.h>
using namespace std;
string a[100000];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,b,bn,x,a;
	
	cin>>n>>m;

	m!=0;
	for(int i=0; i<m; i++) {
		cin>>a[i]

		for(int j=0; j<m; j++) {
			if(a[i]*m>=a[n]) {
				b=n-(m-i);
			}
			if(a[i+1]*b>=a[n]) {
				bn=(n-1)-(b-i);
				x++;
			};
		}

	}

	cout<<x;




	fclose(stdin);
	fclose(stdout);
	return 0;
}




















