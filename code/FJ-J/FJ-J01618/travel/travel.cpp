#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int rc=(c1[0]-'0')*10+c1[1]-'0';
	int xc=(c2[0]-'0')*10+c2[1]-'0';
	if(rc==xc){
		cout<<1;
		int r1=(s1[0]-'0')*10+s1[1]-'0';
		int x1=(s2[0]-'0')*10+s2[1]-'0';
		if(r1==x1){
			cout<<1;
			char r2=s1[2],x2=s2[2];
			if((r2<'D'&&x2<'D')||(r2>'C'&&x2>'C')){
				cout<<1;
				if(abs(r2-x2)==1){
					cout<<1;
				}else{
					cout<<0;
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