#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("freopen.string","r","string.in");
	freopen("freopen.string","w","string.out");
	string c,b,d;
	int n,m,a=0;
	cin>>n;
	for(int i=0;i<n/2;i++){
		cin>>m>>c;
		b+=c;
		a+=m;
	}
	for(int i=0;i<n/2;i++){
		cin>>m>>c;
		a+=m;
		d+=c;
	}
	cout<<a/2;
	return 0;
}
