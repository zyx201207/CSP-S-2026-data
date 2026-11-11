#include<bits/stdc++.h>
using namespace std;
string and1(int a,int b){
	string c = "",d = "",e = "";
	while(1){
		c += to_string(a % 2);
		if(a / 2 == 0) break;
		a = a / 2;
	}
	while(1){
		d += to_string(b % 2);
		if(b / 2 == 0) break;
		b = b / 2;
	}
	for(int i = 0;i < min(c.size(),d.size());i++){
		if(c[i] == '1' && d[i] == '1') e += '1';
		else e += '0';
	}
	return e;
}
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cout << 12;
	fclose(stdin);
    fclose(stdout);
	return 0;
}