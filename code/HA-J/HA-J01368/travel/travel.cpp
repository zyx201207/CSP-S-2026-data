#include<bits/stdc++.h>
using namespace std;
string c,s,g,cc,ss,gg;
int h,hh;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	g=s[2],gg=ss[2];
	s[2]='\0',ss[2]='\0';
	if(c==cc){
		cout<<'1';
		if(s==ss){
			cout<<'1';
			if((g[0]<'D'&&gg[0]<'D')||(g[0]>'C'&&gg[0]>'C')){
				cout<<'1';
				if(abs(g[0]-gg[0])==1){
					cout<<'1';
				}else{
					cout<<"0";
				}
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

