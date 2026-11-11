#include <bits/stdc++.h>
using namespace std;
string c="";
int main(){
	freopen(string.in,"r",stdin);
	freopen(string.out,"w",stdout);
	int n,a,s=0,m=0;
	string b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin >>a >>b;
		for(int j=0;j<a;j++){
			c+=b;
		}
		s+=a;
	}
	for(int i=0;i<s/2;i++){
		if(c[i]!=c[s-i]){
			m++;
		}
	}
	if(m%2==1){
		m--;
	}
	cout <<m;
	return 0;
}
