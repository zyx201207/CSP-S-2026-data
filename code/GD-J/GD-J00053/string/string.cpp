#include <bits/stdc++.h>
using namespace std;

string f(string s) {
	string ot = "";
	int size = s.size();
	for (int i=0;i<size;i++){
		ot+=s[size-i-1];
		// cout<<s[size-i-1];
	}
	return ot;
}

int main(){
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	string s="";
	char z;
	int n,m;
	cin>>n;
	for (int i=0;i<n;i++) {
		cin>>m;
		cin>>z;
		for (int j=0;j<m;j++) {
			s+=z;
		}
	}
	string ns = f(s);
	int count = 0;
	int size = s.size();

	for(int i=0;i<=size;i++){
		if(s[size-1-i]!=ns[size-1-i]){
			s[size-1-i] = ns[size-1-i];
			ns = f(s);
			count+=1;
		}
		else{
			s[size-1-i]=EOF;
			ns[size-1-i]=EOF;
		}
	}

	cout<<count;
	return 0;
} 
