#include <bits/stdc++.h>
using namespace std;
int c1,c2,s2,s1;
int main(){
	freopen("travel.in","r",stdin);
	freopem("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == s2){
		cout << "1111";
	}
	else if (c1 != c2)
	    cout << "0000";
	return 0;
}
