#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	map<char,bool>mp;
	mp['A']=1,mp['B']=1,mp['C']=1,mp['E']=0,mp['F']=0;
	if(c1==c2){
		cout<<"1";
		string q=s1.substr(0,2);
		string w=s2.substr(0,2);
		if(q==w){
			cout<<"1";
			if(mp[s1[2]]==mp[s2[2]]){
				cout<<"1";
				if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
					cout<<"0\n";
				}
				else cout<<"1\n";
			}
			else cout<<"00\n";
		}
		else cout<<"000\n";
	}
	else cout<<"0000\n";
	return 0;
}

