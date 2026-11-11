#include <bits/stdc++.h>
using namespace std;
string s,ss,c,cc;
bool f;
long long ans,ans2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s >> ss >> c >> cc;
	if(s.size()!=c.size()){
		cout << "0000";
		return 0;
	}else{
		f=1;
		for(int i=0;i<s.size();i++){
			if(s[i]!=c[i]){
				cout << "0000";
				f=0;
				return 0; 
			}
		}
	}
	f=1;
	for(int i=0;i<ss.size();i++){
		if(ss[i]>='0'&&ss[i]<='9'){
			if(ss[i]!=cc[i]){
				cout << "1000";
				f=0;
				return 0;
			}
		}
	}
	if(ss[ss.size()-1]=='A'||ss[ss.size()-1]=='B'||ss[ss.size()-1]=='C'){
		if(cc[cc.size()-1]=='D'||cc[cc.size()-1]=='F'){
			cout << "1100";
			return 0;
		}
	}
	if(ss[ss.size()-1]=='D'||ss[ss.size()-1]=='F'){
		if(cc[cc.size()-1]=='A'||cc[cc.size()-1]=='B'||cc[cc.size()-1]=='C'){
			cout << "1100";
			return 0;
		}
	}
	if(ss[ss.size()-1]==(cc[cc.size()-1]-1)||ss[ss.size()-1]==(cc[cc.size()-1]+1)){
		if((ss[ss.size()-1]=='D'&&cc[cc.size()-1]=='C')||(ss[ss.size()-1]=='C'&&cc[cc.size()-1]=='D')){
			cout << "1110";
			return 0;
		}else{
			cout << "1111";
			return 0;
		}
	}else{
		if((ss[ss.size()-1]=='D'&&cc[cc.size()-1]=='F')||(ss[ss.size()-1]=='F'&&cc[cc.size()-1]=='D')){
			cout << "1111";
			return 0;
		}else{
			cout << "1110";
			return 0;
		}
	}
	return 0;
}
