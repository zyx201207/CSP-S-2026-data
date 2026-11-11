#include <bits/stdc++.h>
using namespace std;

bool ishw(string a,string b){
	string t;
	bool f = true;
	for (int i = 0;i < a.size();i ++) t = a[i] + t;
	for (int i = 0;i < a.size();i ++){
		if (t[i] != b[i]) f = false;
	}
	return f;
}
int main(){
	string s1 = "1234";
	string s2 = "4321";
	cout<<ishw(s1,s2); 
	return 0;
}

