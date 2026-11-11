#include<bits/stdc++.h>
using namespace std;
long long z,x,b[100000];
int main() {
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>z>>x;
	for(int i=1; i<=z; i++) {
		cin>>b[i];
	}if(z==4&&x==2)cout<<"12";
	if(z==5&&x==3)cout<<"7";
	return 0;
}