#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define cin fin
#define cout fout
ifstream fin("travel.in");
ofstream fout("travel.out");
bool room(string& c1,string& c2){
	if(c1==c2)return true;
	return false;
}
bool line(string& s1,string& s2){
	if(s1[0]==s2[0] && s1[1]==s2[1])return true;
	return false;
}
bool side(string& s1,string& s2){
	string a = "ABC";
	bool s1s=false;
	bool s2s = false;
	for(auto x:a){
		if(s1[2]==x){
			s1s = true;
		}
		if(s2[2]==x){
			s2s = true;
		}
	}
	if(s1s && s2s)return true;
	if(!s1s && !s2s)return true;
	return false;
}
bool near(string& s1,string& s2){
	char s1x = s1[2];
	string a = "ABC";
	ll id1 = -1;
	bool ans = false;
	for(ll i = 0;i < 3;i++){
		if(a[i]==s1x)id1 = i;
	}
	if(id1 - 1>= 0){
		if(a[id1-1]==s2[2])ans = true;
	}
	if(id1 + 1< 3){
		if(a[id1+1]==s2[2])ans = true;
	}
	if(s1[2]=='D'&&s2[2]=='F'){
		ans = true;
	}
	if(s1[2]=='F'&&s2[2]=='D'){
		ans = true;
	}
	return ans;
}
int main(){
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool ans1 = room(c1,c2);
	bool ans2 = line(s1,s2);
	bool ans3 = side(s1,s2);
	bool ans4 = near(s1,s2);
	if(ans1){
		cout << 1;
	}else cout << 0;
	if(ans1 && ans2){
		cout << 1;
	}else cout << 0;
	if(ans1 && ans2 && ans3){
		cout << 1;
	}else cout << 0;
	if(ans1 && ans2 && ans3 && ans4){
		cout << 1;
	}else cout << 0;
	
	return 0;
	
}
