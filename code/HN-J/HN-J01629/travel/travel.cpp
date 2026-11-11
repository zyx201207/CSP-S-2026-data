#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2,h1,h2;
char l1,l2;
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	h1=(s1[0]-'0')*10+(s1[1]-'0'),h2=(s2[0]-'0')*10+(s2[1]-'0');
	l1=s1[2],l2=s2[2];
	if(c1==c2){
		if(h1==h2){
			if((l1<='C'&&l2<='C')){
				if(abs(l1-l2)==1) cout<<"1111";
				else cout<<"1110";
			}else if(l1>'C'&&l2>'C') cout<<"1111";
			else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
