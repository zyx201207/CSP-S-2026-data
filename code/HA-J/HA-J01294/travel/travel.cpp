#include<bits/stdc++.h>
using namespace std;
string a,b,s1,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b) {
		cout<<"1";
		int f=0;
		for(int i=0; i<s1.size()-1; i++) {
			if(s1[i]!=s2[i])f=1;
		}
		if(!f) {
			cout<<"1";
			if(((s1[s1.size()-1]>='A'&&s1[s1.size()-1]<='C')&&(s2[s2.size()-1]>='A'&&s2[s2.size()-1]<='C'))||((s1[s1.size()-1]>='E'&&s1[s1.size()-1]<='F')&&(s2[s2.size()-1]>='E'&&s2[s2.size()-1]<='F'))) {
				cout<<"1";
				int num=abs(int(s1[s1.size()-1]-s2[s2.size()-1]));
				if(num==1&&!(s1[s1.size()-1]=='C'&&s2[s2.size()-1]=='D')&&!(s1[s1.size()-1]=='D'&&s2[s2.size()-1]=='C')) {
					cout<<"1";
				} else cout<<"0";
			} else cout<<"00";
		} else cout<<"000";
	} else cout<<"0000";
	return 0;
}
