#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if (c1 == s1) cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	string tx = c2,ty = s2;
	
	tx[2] = 0;
	ty[2] = 0;
	if (tx == ty) cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	
	if (c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C') {
		if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
			cout<<"1";
			if (abs(c2[2] - s2[2]) == 1) {
				cout<<"1";
				return 0;
			}
			else {
				cout<<"0";
				return 0;
			}
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	else if (c2[2] == 'D' || c2[2] == 'F') {
		if (s2[2] == 'D' || s2[2] == 'F') {
			cout<<"11";
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	return 0;
} 
