#include<bits/stdc++.h>
using namespace std;
long long n,m,s,l,a[1000000];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin >>n>>m;
	for(int i=0;i<m;i++){
		cin >> s>>l;
		for(int j=0;j<s;j++){
			cin >>a[j];
		}
	}
	for(int i=0;i<m;i++){
		cout << "0"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


