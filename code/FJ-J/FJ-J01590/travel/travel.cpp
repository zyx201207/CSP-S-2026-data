#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,s1,s2,t;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		t+='1';
		if (s1[0]==s2[0] && s1[1]==s2[1]){
			t+='1';
			if ((s1[2]<='C' && s2[2]<='C') || (s1[2]>='E' && s2[2]<='E')){
				t+='1';
				if (abs((int)s1[2]-s2[2])==1){
					t+='1';
				}
				else{
					t+='0';
				}
			}
			else{
				t+="00";
			}
		}
		else{
			t+="000";
		}
	}
	else{
		t+="0000";
	}
	cout<<t;
	return 0;
}
