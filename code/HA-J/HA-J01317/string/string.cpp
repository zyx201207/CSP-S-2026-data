#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b,z=0;
	cin>>a;
	char c;
	for(int i=0;i<a;i++){
		cin>>b>>c;
		z+=b;
	}
	cout<<z/2;
	return 0;
}
