#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1st,s2st;
int s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>c1>>s1>>s1st>>c2>>s2>>s2st;
	if(c1==c2){
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			if((s1st<=67&&s2st<=67)||(s1st>67&&s2st>67)){
				cout<<"1";
				if(abs(s1st-s2st)==1)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
