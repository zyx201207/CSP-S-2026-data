#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1[0]==c2[0]&&c1[1]==c2[1]){
    	cout << 1;
	}
	else {
		cout << 0000;
	} 
	for (int i=0;i<3;i++){
		if (s1[i]==s2[i]){
			cout << 1;
		}
	}
    return 0;
}
