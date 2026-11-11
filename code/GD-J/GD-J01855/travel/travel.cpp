#include<bits/stdc++.h>
using namespace std;
bool check1(string x , string y){
	int len1 = (int)x.size();
	int len2 = (int)y.size();
	if(len1 != len2) return false;
	for(int i = 0 ; i < len1 - 1 ; i++){
		if(x[i] != y[i]) return false;
	}
	return true;
}
bool check2(string x , string y){
	int len1 = (int)x.size();
	int len2 = (int)y.size();
	if((x[len1 - 1] - 'A' <= 2 && y[len2 - 1] - 'A' <= 2) || (x[len1 - 1] - 'A' > 2 && y[len2 - 1] - 'A' > 2)){
		return true;
	}
	return false;
}
bool check3(string x , string y){
	int len1 = (int)x.size();
	int len2 = (int)y.size();
	if(x[len1 - 1] - y[len2 - 1] == 1 || y[len2 - 1] - x[len1 - 1] == 1){
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	string c1 , s1 , c2 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool cc = true;
	if(c1 == c2){
		cout << 1;
		cc = true;
	}
	else{
		cout << 0;
		cc = false;
	}
	bool tt = check1(s1 , s2);
	if(tt && cc){
		cout << 1;
	}
	else{
		cout << 0;
	}
	int gg = check2(s1 , s2);
	if(tt && cc && gg){
		cout << 1;
	}
	else{
		cout << 0;
	}
	int yd = check3(s1 , s2);
	if(tt && cc && gg && yd){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
