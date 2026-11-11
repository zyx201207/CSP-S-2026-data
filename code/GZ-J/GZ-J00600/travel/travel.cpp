//GZ-J00600 贵阳华师一学校 蒋金珂
#include<bits/stdc++.h>
using namespace std;
int main() {freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	map<char,int>mp;
	mp['A']=1;
	mp['B']=2;
	mp['C']=3;
	mp['D']=4;
	mp['F']=5;
	if(c1!=c2) {
		cout<<"0000";
	} else {
		cout<<1;
		if(s2[0]!=s1[0]||s2[1]!=s1[1]) {
			cout<<"000";
		} else {
			cout<<1;
			char cc1=s1[2],cc2=s2[2];

			if(mp[cc1]>3&&mp[cc2]<=3) {
				cout<<"00";
			} else if(mp[cc1]<=3&&mp[cc2]>3) {
				cout<<"00";
			} else {
				cout<<1;
				if(abs(mp[cc1]-mp[cc2])==1) {
					cout<<1;
				} else {
					cout<<0;
				}
			}
		}
	}
}

