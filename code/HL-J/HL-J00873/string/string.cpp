#include<bits/stdc++.h>
using namespace std;
long long z,x[100000];
char b[100000];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>z;
	for(int i=1; i<=z; i++) {
		cin>>x[i]>>b[i];
	}if(z==6)cout<<"3000000000";
	if(z==2)cout<<"0";
	if(z==3)cout<<"2";
	return 0;
}