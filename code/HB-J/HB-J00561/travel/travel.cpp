#include<bits/stdc++.h>
using namespace std;

char c1[3],s1[4],c2[3],s2[4];
int a1,b1,a2,b2;
char t[3];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a1 = c1[1]-'0';
	if(c1[0] == '1'){
		a1 += 10;
	}
	a2 = c2[1]-'0';
	if(c2[0] == '1'){
		a2 += 10;
	}
	b1 = s1[1]-'0';
	if(s1[0] == '1'){
		b1 += 10;
	}
	b2 = s2[1]-'0';
	if(s2[0] == '1'){
		b2 += 10;
	}
	t[0] = s1[2];
	t[1] = s2[2];
	if(a1 == a2){
		cout << 1;
		if(b1 == b2){
			cout << 1;
			if(t[0] == 'A'||t[0]=='B'||t[0]=='C'){
				if(t[1]=='A'||t[1]=='B'||t[1]=='C'){
					cout << 1;
					if(t[0]=='B'){
						cout << 1;
					}else if(t[0]=='A'&&t[1]=='B'){
						cout << 1;
					}else if(t[0] == 'C' && t[1] == 'B'){
						cout << 1;
					}else{
						cout << 0;
					}
				}else{
					cout << "00";
				}
			}else{
				if(t[1]=='D'||t[1]=='F'){
					cout << 1;
					cout << 1;
				}else{
					cout << "00";
				}
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
