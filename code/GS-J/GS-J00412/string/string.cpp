#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int l,b=0;
	string s;
	cin>>l;
	for(int i=0;i<l;i++){
		int h;
		char z;
		cin>>h>>z;
		for(int j=0;j<h;j++){
			s[i+j]=z;
		}
	}
	for(int k=0;k<l;k++){
		if(!(s[k]==s[l-1-k])){
			b++;
		}
	}
	cout<<b;
	return 0;
}
