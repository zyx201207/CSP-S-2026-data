//GZ-J00187  遵义市新蒲中学 王墨霖 
#include <bits/stdc++.h>
using namespace std;
int u(string a){
	int p=0;
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1]) p++;                  
	}
	return p;
}
int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out ","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		char b;
		cin>>b;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	cout<<u(s);
	return 0;
}

