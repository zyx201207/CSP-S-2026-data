#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define psb push_back
#define db double
string c1,c2,s1,s2;
bool chk(char a,char b){
	if(a=='A'||a=='C')return b=='B';
	if(a=='B')return b=='A'||b=='C';
	if(a=='D')return b=='F';
	if(a=='F')return b=='D';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else{
		if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"1000";
		else{
			if(('C'>=s1[2]&&'C'>=s2[2])||('D'<=s1[2]&&'D'<=s2[2])){
				if(chk(s1[2],s2[2]))cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
	}
return 0;}
