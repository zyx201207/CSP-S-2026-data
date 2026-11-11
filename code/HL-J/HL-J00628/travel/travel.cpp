#include<bits/stdc++.h>
using namespace std;

int c1,c2;
char s1[4],s2[4];
int T = false;
int T1 = false;
int T2 = false;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>c1;
	cin >>s1;
	cin >>c2;
	cin >>s2;
	if(c1 == c2){
		cout <<1;
		T = true;
	}
	else
		cout <<0;
	if(s1[0] == s2[0] && s1[1] == s2[1] && T){
		cout <<1;
		T1 = true;
	}
	else
		cout<<0;
	if(((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'D' || s1[2]=='F') && (s2[2] == 'D' || s2[2]=='F')) && T1){
		cout <<1;
		T2 = true;
	}

	else
		cout <<0;
	if(s1[2] == 'F')
		s1[2] = 'E';
	if(s2[2] == 'f')
		s2[2] == 'E';
	if(abs(int(s1[2]) - int(s2[2])) == 1 && T2)
		cout <<1;
	else
		cout <<0;
	return 0;
}