#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string c1,s1,c2,s2;
LL check(char c){
	if(c=='A' || c=='B' || c=='C') return 1;
	else return 2;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
		cout<<"1";
		LL x=(s1[0]-'0')*10+s1[1]-'0';
		LL y=(s2[0]-'0')*10+s2[1]-'0';
		if(x==y){
			cout<<"1";
			if(check(s1[2])==check(s2[2])){
				cout<<"1";
				if((s1[2]<s2[2] && s1[2]+1==s2[2]) || (s1[2]>s2[2] && s1[2]-1==s2[2])) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
    else cout<<"0000";
    return 0;
}
