//GZ-J00413ºØÖªÓîº­ 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int q1 = 0,q2 = 0,q3 = 0,q4 = 0;
	int jg =  int(s1[2] - s2[2]);
	if(c1 == c2){
		q1 = 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			q2 = 1;
			if(s1[2] < 68 && s2[2] < 68 || s1[2] >= 68 && s2[2] >= 68){
				q3 = 1;
				if(jg == 1 || jg == -1){
					q4 = 1;
				}
			}
		}
	}
	cout << q1 << q2 << q3 << q4;
	return 0;
}
