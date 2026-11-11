#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=100;
string c1,c2;
string s1,s2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1==c2){
		for(int i=0;i<s1.size()-1;i++){
			if(s1[i]!=s2[i]){
				cout<<"1000";
				return 0;
			}
		}
		if((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D')){
			cout<<"1100";
			return 0;
		}
		if(!(s1[2]+1==s2[2]||s2[2]+1==s1[2])){
			cout<<"1110";
			return 0;
		}
	}else{
	 	cout<<"0000";
	 	return 0;
	}
	cout<<"1111";
	return 0;
} 
