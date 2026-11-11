#include <bits/stdc++.h>
using namespace std;
long long tx=0,tp=0,tc=0,xl=0;
long long c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		tx=1;//同车厢 
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			tp=1;//同排
			if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					tc=1;//abc区同侧 
					if(s2[2]!='A'&&s2[2]!='C'){
						xl=1;//非ac相邻 
					}
					else if(s2[2]!='C'&&s2[2]!='A'){
						xl=1;//非ca相邻 
					}
				}
			} 
			else if(s1[2]=='D'||s1[2]=='E'){
				if(s2[2]=='D'||s2[2]=='E'){
					tc=1;//de区同侧 
					xl=1;//只有两个位置，只能相邻 
				}
			}
		}
	}
	cout<<tx<<tp<<tc<<xl;
	return 0;
}
