#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,a[1000000],m=0;
	char b[1000000];
	string c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}

	for(int i=1;i<=n;i++){
		for(int e=1;e<=a[i];e++)	{c+=b[e];
		}
	}
	
	

	return 0;
}
