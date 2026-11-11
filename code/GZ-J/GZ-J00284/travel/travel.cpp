//GZ-J00284 БѕКўжабЇ ЫяЫМем 
#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	for(int i=0;i<2;i++) cin >> c1[i];
	for(int i=0;i<3;i++) cin >> s1[i];
	for(int i=0;i<2;i++) cin >> c2[i];
	for(int i=0;i<3;i++) cin >> s2[i];
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout << "1";
		if(s1[1]==s2[1]){
			cout << "1";
			if((s1[2]>='A'&&s2[2]>='A'&&s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'&&s1[2]<='F'&&s2[2]<='F')){
				cout << "1";
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					cout << "1";
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else{
		cout << "0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
