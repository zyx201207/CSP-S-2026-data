#include<bits/stdc++.h>
#define int long long
using namespace std;
string p,q,s1,s2;
bool v[4];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>p>>s1>>q>>s2;

	if(p==q){
		v[0]=1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			v[1]=1;
			if((s1[2]<='C'&&s2[2]<='C')||(s2[2]>'C'&&s1[2]>'C')){
				v[2]=1;
				if(s2[2]-'0'==s1[2]-'0'+1||s1[2]-'0'==s2[2]-'0'+1){
					v[3]=1;
				}
			}
		}
	}
	else v[0]=0;
	for(int i=0;i<4;i++){
		if(v[i])cout<<1;
		else cout<<0;
	}
	return 0;
}
