#include<bits/stdc++.h>
using namespace std;
string s,c,ss,cc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>c>>ss>>cc;
	if(s!=ss){
		cout<<"0000";
		return 0;
	}else{
		if(c[0]!=cc[0]||c[1]!=cc[1]) {
			cout<<"1000";
			return 0;
		}
		else{
			if((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(cc[2]=='D'||cc[2]=='E')){
				cout<<"1100";
				return 0;
			}
			else{
				if((c[2]=='A'&&cc[2]=='B')||(c[2]=='B'&&cc[2]=='C')||(c[2]=='D'&&cc[2]=='E')){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
			}
		}
	}
	return 0;
}
