#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a,b;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> c2 >> s1 >> s2;
	b = s2[0] * 10 + s2[1];
	a = c2[0] * 10 + c2[1];
	if(c1[0]==s1[0] && c1[1]==s1[1]){
		cout << 1;
		if(a==b){
			cout << 1;
			if((c2[2]<'D' && s2[2]<'D') || (c2[2]>='D' && s2[2]>='D')){
				cout << 1;
				if((a+1==b || a-1==b || a==b) && (c2[2]+1==s2[2] || c2[2]-1==s2[2] || c2[2]==s2[2])){
					cout << 1;
				}else cout << 0;
			}else cout << "00";
		}else cout << "000";
		return 0;
	}
	cout << "0000";
	return 0;
}
