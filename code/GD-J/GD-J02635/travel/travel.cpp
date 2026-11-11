#include<bits/stdc++.h>
using namespace std;



int main(){
	string c1, s1, c2, s2;
	int aa=0, ab=0, ac=0, ad=0, d1=0, d2 = 0;
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int cha = 0;
	if(c1==c2){
		aa =1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			ab = 1;
			if(s1[2]=='D'||s1[2]=='E')d1 = 1;
			if(s2[2]=='D'||s2[2]=='E')d2 = 1;
			if(d1 == d2){
                ac = 1;
                cha = s1[2] - s2[2];
                if(cha<0)cha = -cha;
                if(cha == 1)ad = 1;
            }
		}
	}


	cout << aa << ab << ac << ad;
	return 0;
}
