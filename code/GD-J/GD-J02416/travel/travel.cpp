#include <bits/stdc++.h>
using namespace std;

char rc[2],xc[2];
char rz[3],xz[3];
int c1,c2,p1,p2;
int main(){
	//freopen("travel.in","c",stdin);
	//freopen("travel.out","w",stdout);
	for (int i = 0;i < 2;i ++) cin>>rc[i];
	for (int i = 0;i < 3;i ++) cin>>rz[i];
	for (int i = 0;i < 2;i ++) cin>>xc[i];
	for (int i = 0;i < 3;i ++) cin>>xz[i];
	c1 = rc[1] - '0';
	if (rc[0] == '1') c1 = c1 + 10;
	c2 = xc[1] - '0';
	if (xc[0] == '1') c2 = c2 + 10;
	if (c1 == c2){
		cout<<'1';
		p1 = rz[1] - '0';
		if (rz[0] == '1') p1 = p1 + 10;
		p2 = xz[1] - '0';
		if (xz[0] == '1') p2 = p2 + 10;
		if (p1 == p2){
			cout<<'1';
			bool q1 = false;
			if (xz[2] == 'A' && rz[2] == 'B') q1 = true;
			bool q2 = false;
			if (xz[2] == 'B' && rz[2] == 'A') q2 = true;
			bool q3 = false;
			if (xz[2] == 'B' && rz[2] == 'C') q3 = true;
			bool q4 = false;
			if (xz[2] == 'C' && rz[2] == 'B') q4 = true;
			bool q5 = false;
			if (xz[2] == 'A' && rz[2] == 'C') q5 = true;
			bool q6 = false;
			if (xz[2] == 'C' && rz[2] == 'A') q6 = true;
			bool q7 = false;
			if (xz[2] == 'D' && rz[2] == 'F') q7 = true;
			bool q8 = false;
			if (xz[2] == 'F' && rz[2] == 'D') q8 = true;
			if (q1 || q2 || q3 || q4 || q5 || q6 || q7 || q8){
				cout<<'1';
				if (q1 || q2 || q3 || q4 || q7 || q8) cout<<'1';
				else cout<<'0';
			}else cout<<"00";
		}else cout<<"000"; 
	}else cout<<"0000";
    
	return 0;
}

