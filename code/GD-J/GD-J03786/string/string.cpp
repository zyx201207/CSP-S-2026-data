#include<bits/stdc++.h>
using namespace std;
int main(){
	feropen("string.in","r",std);
	freopen("string.out","w",std);
	long long e=0,f=0;
	int a,b;
	char c;
	string d;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b;
		cin>>c;
		for(int j=0;j<b;j++){
			d[e]=c;
			e++;
		}
	}
	for(int i=0;i<e/2;i++){
		if(d[i]!=d[e-i-1]) f++;
	}
	cout<<f;
	return 0;
}
