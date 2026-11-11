#include<bits/stdc++.h>
using namespace std;
#define int long long
int pan(char a,char b){
	if(a=='A'&&b=='B') return 1;
	if(a=='B'&&b=='A') return 1;
	if(a=='C'&&b=='B') return 1;
	if(a=='B'&&b=='C') return 1;
	
	if(a=='D'&&b=='F') return 1;
	if(a=='F'&&b=='D') return 1;
	if(a=='A'&&b=='C') return 2;
	if(a=='C'&&b=='A') return 2;
	else return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&pan(s1[2],s2[2])==1){
		cout << "1111";
	}
	else if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&pan(s1[2],s2[2])==2){
		cout << "1110";
	}
	else if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout << "1100";
	}
	else if(c1==c2){
		cout << "1000";
	}
	else cout << "0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

