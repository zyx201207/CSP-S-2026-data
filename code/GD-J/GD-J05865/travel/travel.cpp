#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	string a="";
	int b=s1[2]-'A'+1,c=s2[2]-'A'+1;
	if(c1==c2){
		a+='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a+='1';
			if(b+c==3||b+c==5||b+c==9||b+c==4){
				a+='1';
				if(b+c==3||b+c==5||b+c==9) a+='1';
				else a+='0';
			}
			else a+="00";
		}
		else a+="000";
	}
	else a="0000";
	cout<<a;
	return 0;
}
