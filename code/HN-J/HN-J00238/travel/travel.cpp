#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1 , s1 , c2 , s2;
	cin>>c1>>s1>>c2>>s2;
	string s= "" ;
	if(s1[2] < s2[2]) s = s + s1[2] + s2[2];
	else s = s + s2[2] + s1[2];
	
//	cout<<s<<"\n";

	if(c1 != c2) cout<<"0000";  //车厢不同 
	else {
		cout<<"1";
		if(s1[0] == s2[0] and s1[1]==s2[1]) {  //车厢同  and 同一排 
			cout<<"1";
			if(s == "AB" or s =="AC" or s=="BC" or s=="DF") {  // 同一侧 
				cout<<"1";
				if(s=="AB" or s=="BC" or s=="DF") {   //相邻 
					cout<<"1";
				} else {
					cout<<"0";
				}
			} else {
				cout<<"00";
			}
		} else {
			cout<<"000";
		}
	}


	return 0;
}
