#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2,t1,t2="",d1,d2="",g1,g2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> c1 >> s2 >> c2;
	if(s1 == s2){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	
	t1 = c1.substr(0,c1.size()-1);
	d1 = c2.substr(0,c2.size()-1);

	t2 += c1[2];
	d2 += c2[2];
	
	if(t1 == d1) cout << "1";
	else cout << "0";
	if(t1 == d1 && (t2 <= "C" && d2 <= "C") || (t2>="D"&&d2>="D")) cout << "1";
	else cout << "0";
	if((t2>="D"&&d2>="D") && t1 == d1) cout << "1";
	else if((t2>"A"&&d2>"A"&&t2 < "D"&&d2<"D") || (t2<"C"&&d2<"C") && t1 == d1) cout << "1";
	else cout << "0";
	return 0;
}

