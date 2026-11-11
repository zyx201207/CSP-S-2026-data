#include<bits/stdc++.h>
using namespace std;
int c1,c2,ans2,ans3,ans4;
string s1,s2,t1,t2;
unordered_map<char,bool> mp = {{'A',1},{'B',1},{'C',1}};
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	cin >>t1 >> s1 >> t2 >> s2;
	c1=stoi(t1),c2=stoi(t2);
	if(c1 != c2) {
		cout<<"0000\n";
	}else{
		int k1,k2;
		string ns1 = s1,ns2 = s2;
		ns1.pop_back(); ns2.pop_back();
		k1 = stoi(ns1); k2 = stoi(ns2);
		if(k1 == k2) {
			ans2=1;
			if((mp.count(s1.back())&&mp.count(s2.back()))||((!mp.count(s1.back()))&&(!mp.count(s2.back())))){
				ans3=1;
				if(s1.back()=='A' && s2.back() == 'B') {
					ans4=1;
				}else if(s1.back()=='B'&&(s2.back()=='C'||s2.back()=='A')){
					ans4=1;
				}else if(s1.back()=='C'&&s2.back()=='B'){
					ans4=1;
				}else if(s1.back() == 'D' && s2.back() == 'F'){
					ans4=1;
				}else if(s1.back()=='F' && s2.back() == 'D'){
					ans4=1;
				}
			}
		}cout<<1<<ans2<<ans3<<ans4<<'\n';
	}
	return 0;
} 
