#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	char c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2){
		cout << "1111";
	}else if(s1 != s2){
	    cout << "1110";
	}else{
		cout << "0111";
	}
	return 0;
}
