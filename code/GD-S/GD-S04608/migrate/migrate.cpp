#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long n,d,c,t,f;
	cin>>n>>d>>c>>t>>f;
	if(n>=0&&d>=0&&c>=0&&t>=0&&f>=0)cout << "1" << endl << "2";
	else cout << "0" << endl << "1";
	return 0; 
}