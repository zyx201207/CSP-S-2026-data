#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i = 0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		s += a*b;
	}
	cout<<'0';
	return 0;
}
