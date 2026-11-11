#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,s1,s2;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			map<char,int> mp;
			mp[s1[2]]++;
			mp[s2[2]]++;
			if(mp['A']&&mp['B']||mp['B']&&mp['C']||mp['f']&&mp['D']||mp['A']&&mp['C']){
				cout<<"1";
				if(mp['A']&&mp['B']||mp['B']&&mp['C']||mp['f']&&mp['D'])cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";

		return 0;
}
