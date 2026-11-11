#include<bits/stdc++.h>
using namespace std;
int c,cz;
string s,sz;
int main(){
	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>c>>s>>cz>>sz;
	if(c==cz){
		cout<<1;
		if(s[1]==sz[1]){
			cout<<1;
			if((s[2]<='C'&&sz[2]<='C')||(s[2]>='D'&&sz[2]>='D')){
				cout<<1;
				if(1==abs(s[2]-sz[2]))cout<<1;
				else cout<<0;
			}
			else
			cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
