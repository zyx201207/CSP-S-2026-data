#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		if(s1 == "01A" || s1 == "01B" || s1 == "01C" || s1 == "01D" && s2 == "01A" || s2 == "01B" || s2 == "01C" || s2 == "01D"){
			cout << 1;
		}
		else {
			cout << 0;
		}
		if(s1 == "01A" && s2 == "01B" || s1 == "01B" && s2 == "01C" || s1 == "01A" && s2 == "01C" || s1 == "01D" && s2 == "01E" || s2 == "01A" && s1 == "01B" || s2 == "01B" && s1 == "01C" || s2 == "01A" && s1 == "01C" || s2 == "01D" && s1 == "01E"&& c1 == c2){
			cout << 1;
		}
		else{
			cout << 0;
		}
		if(s1 == "01A" && s2 == "01B" || s1 == "01B" && s2 == "01C" || s1 == "01D" && s2 == "01E"){
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	return 0;
}
