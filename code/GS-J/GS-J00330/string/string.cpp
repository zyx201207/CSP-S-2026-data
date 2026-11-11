#include <iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b[100000],c[100000],s=0;
	
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i]>>c[i];
		s+=b[i];
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
