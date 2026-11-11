#include<bits/stdc++.h>
using namespace std;
string c,c1,s,s1,sum="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>c1>>s>>s1;
	if(c==s){
		if(c1[0]==s1[0]&&c1[1]==s1[1]){
			if((c1[2]>='A'&&c1[2]<='C'&&s1[2]>='A'&&s1[2]<='C')||(c1[2]>='D'&&c1[2]<='E'&&s1[2]>='D'&&s1[2]<='E')){
				if(((c1[2]=='A'&&s1[2]=='B')||(c1[2]=='B'&&s1[2]=='A'))||((c1[2]=='C'&&s1[2]=='B')||(c1[2]=='B'&&s1[2]=='C'))||((c1[2]=='E'&&s1[2]=='D')||(c1[2]=='D'&&s1[2]=='E'))){
				}else{
					cout<<"1110";
					return 0;
				}
			}else{
				cout<<"1100";
				return 0;
			}
		}else{
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	cout<<"1111";
	return 0;
}
