#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long a,b;
bool f(){
	if(s1[2] >= 'D' || s2[2] >= 'D'){
		if((int)(s1[2]) - (int)(s2[2]) != 1 && (int)(s1[2]) - (int)(s2[2]) != -1 && (int)(s2[2]) - (int)(s1[2]) != 1 && (int)(s2[2]) - (int)(s1[2]) != -1){
			return 0;
		}
	}else if((int)(s1[2]) - (int)(s2[2]) != 2 && (int)(s1[2]) - (int)(s2[2]) != -2 && (int)(s2[2]) - (int)(s1[2]) != 2 && (int)(s2[2]) - (int)(s1[2]) != -2 && (int)(s1[2]) - (int)(s2[2]) != 1 && (int)(s1[2]) - (int)(s2[2]) != -1 && (int)(s2[2]) - (int)(s1[2]) != 1 && (int)(s2[2]) - (int)(s1[2]) != -1){
			return 0;
	}
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a = s1[0] + s1[1];
	b = s2[0] + s2[1];
	if(c1 != c2){
		cout <<"0000";
	    return 0;
	}else if(a != b){
		cout <<"1000";
	    return 0;
	}else if(f()){
		cout <<"1100";
	    return 0;
	}else if((int)(s1[2]) - (int)(s2[2]) != 1 && (int)(s1[2]) - (int)(s2[2]) != -1 && (int)(s2[2]) - (int)(s1[2]) != 1 && (int)(s2[2]) - (int)(s1[2]) != -1){
		cout <<"1110";
	    return 0;
	}else{
		cout <<"1111";
	}
	return 0;
} 
