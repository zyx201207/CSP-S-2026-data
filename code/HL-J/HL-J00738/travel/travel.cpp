#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a[5] = "0000";
void p(){
	for(int i = 0;i<4;i++){
		cout << a[i];
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		a[0] = '1';
	}else{
		p();
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		a[1] = '1';
	}else{
		p();
		return 0;
	}
	if((s1[2] <='C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')){
		a[2] = '1';
	}else{
		p();
		return 0;
	}
	char mx,mn;
	if(s1[2] > s2[2]){
		mx = s1[2];
		mn = s2[2];
	}else{
		mx = s2[2];
		mn = s1[2];
	}
	if((mn == 'A' && mx == 'B') || (mn == 'B' && mx == 'C') || (mn == 'D' && mx == 'F')){
		a[3] = '1';
	}
	p();
	return 0;
}