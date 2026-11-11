#include<bits/stdc++.h>
using namespace std;
int s1,c1;
string s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> c1 >> c2;
	if(s1!=c1){
		cout << "0000";
		return 0;
	}
	int s=int(s2[0]-'0')*10+int(s2[1]-'0');
	int sum=int(c2[0]-'0')*10+int(c2[1]-'0');
	if(sum!=s){
		cout << "1000";
		return 0;
	}
	if(s2[2]=='C'||s2[2]=='B'||s2[2]=='A'){
		if(c2[2]=='D'||c2[2]=='F') {
			cout << "1100";
			return 0;
		}
	}
	if(c2[2]=='C'||c2[2]=='B'||c2[2]=='A'){
		if(s2[2]=='D'||s2[2]=='F') {
			cout << "1100";
			return 0;
		}
	}
	if(int(s2[2]-'A')+1==int(c2[2]-'A')||int(s2[2]-'A')-1==int(c2[2]-'A')){
		cout << "1111";
		return 0;
	}
	else cout << "1110";
	return 0;
}

