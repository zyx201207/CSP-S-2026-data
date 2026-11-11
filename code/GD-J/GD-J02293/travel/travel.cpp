#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,x,y;
	cin>>c>>s>>x>>y;
	if(c[0]==x[0]&&c[1]==x[1]){
		cout<<'1';
		if(s[0]==y[0]&&s[1]==y[1]){
			cout<<'1';
			if(s[2]<='C'&&y[2]<='C'){
				cout<<'1';
				int o=max(s[2]-'0',y[2]-'0');
				int p=min(s[2]-'0',y[2]-'0');
				if(o-p==1){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if(s[2]>'C'&&y[2]>'C'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
