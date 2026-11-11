#include<bits/stdc++.h>
using namespace std;
string cc,ss,ccc,sss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>cc>>ss>>ccc>>sss;
	if(cc==ccc) {
		cout<<"1";
		if(ss[0]==sss[0]&&ss[1]==sss[1]) {
			cout<<"1";
			if((ss[2]-'A'<3&&sss[2]-'A'<3)||(ss[2]-'A'>=3&&sss[2]-'A'>=3)) {
				cout<<"1";
				if(abs(ss[2]-sss[2])==1) cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
} 
