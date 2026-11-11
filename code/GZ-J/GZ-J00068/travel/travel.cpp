//GZ-J00068，阮辰允，贵阳市白云区华师一学校
#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
map<char,bool> m;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	m['D']=m['F']=1;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(m[s1[2]]==m[s2[2]]){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
