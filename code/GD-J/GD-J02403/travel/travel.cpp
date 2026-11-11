#include<bits/stdc++.h>
using namespace std;
char tmp,c[2],c1[3],s[2],s1[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c[0] >> c[1];
	tmp = getchar();
	cin >> c1[0] >> c1[1] >> c1[2];
	tmp = getchar();
	cin >> s[0] >> s[1];
	tmp = getchar();
	cin >> s1[0] >> s1[1] >> s1[2];
	if(c[0] == s[0] && c[1] == s[1]){
		cout << "1";
		if(c1[0] == s1[0] && c1[1] == s1[1]){
			cout << "1";
			if((c1[2] >= 'A' && c1[2] <= 'C' && s1[2] <= 'C' && s1[2] >= 'A') || ((c1[2] == 'D' && s1[2] == 'F') || (c1[2] == 'F' && s1[2] == 'D'))){
				cout << "1";
				if((c1[2] == s1[2] - 1 || c1[2] == s1[2] + 1) || ((c1[2] == 'D' && s1[2] == 'F') || (c1[2] == 'F' && s1[2] == 'D'))){
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			} 
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}

