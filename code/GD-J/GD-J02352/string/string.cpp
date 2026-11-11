#include <bits/stdc++.h>
using namespace std;
int n,wrong=0,x=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin >> a >> b;
		x += a;
		for(int j=1;j<=a;j++){
			s += b;
		}
	}
	int q=0,m=s[q],c=s[x-1];
	while(q<x){
		if(m!=c)  wrong++;
		q++;
		x--;
		m=s[q],c=s[x];
	}
	cout << wrong;
	return 0;
}
