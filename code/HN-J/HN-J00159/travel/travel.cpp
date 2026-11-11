#include <bits/stdc++.h> 
using namespace std;

int main(){
int c1,c2;
string s1,s2;

freopen("travel.in", "r", stdin);
freopen("travel.out", "w", stdout);
cin>>c1>>s1>>c2>>s2;
if(c1==c2){
	cout<<"1";
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout << "1";
		if((int(s1[2]) == 65 && int(s2[2]) == 66 || int(s1[2]) == 65 && int(s2[2]) == 67||int(s1[2])==66&&int(s2[2])==65||int(s1[2])==66&&int(s2[2])==67||int(s1[2])==67&&int(s2[2])==65||int(s1[2])==66&&int(s2[2])==66)||int(s1[2])==68&&int(s2[2])==70||int(s1[2])==70&&int(s2[2])==68){
			cout<<"1";
			if((int(s1[2])==65&&int(s2[2])==66||int(s1[2])==66&&int(s2[2])==67||int(s1[2])==67&&int(s2[2])==66||int(s1[2])==66&&int(s2[2])==65 )||(int(s1[2])==68&&int(s2[2])==70||int(s1[2])==70&&int(s2[2])==68))
			{
			cout<<"1";
			}
			else cout<<"0";
		}
		else cout<<"00";
	}
	else cout<<"000";
}
else cout<<"0000";


return 0;
}
