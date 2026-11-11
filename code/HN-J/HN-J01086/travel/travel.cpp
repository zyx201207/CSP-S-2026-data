#include<bits/stdc++.h>
using namespace std;
string x,s1,y,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>s1>>y>>s2;
	if (x==y){
		cout<<"1";
		string t1="";
		t1+=s1[0];
		t1+=s1[1];
		string t2="";
		t2+=s2[0];
		t2+=s2[1];
		if (t1==t2){
			cout<<"1";
			bool f1=(s1[2]=='A' || s1[2]=='B' || s1[2]=='C');
			bool f2=(s2[2]=='A' || s2[2]=='B' || s2[2]=='C');
			if (f1==f2){
				cout<<"1";
				if (s1[2]+1==s2[2] || s1[2]-1==s2[2]){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
