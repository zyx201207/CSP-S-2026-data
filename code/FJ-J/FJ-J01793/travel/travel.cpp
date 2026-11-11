#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,x,y;
	cin>>c1>>s1>>c2>>s2>>x>>y;
	if(c1==c2){
		cout<<"1";
		if(x==y){
			cout<<"1";
			if(s1[3]=='A'||s1[3]=='B'&&s2[3]=='A'||s2[3]=='B'||s1[3]=='C'){
				cout<<"1";
				if(s1[3]=='B'||s2[3]=='B'){
					cout<<"1";
				}
		             else cout<<"0";
				}else if((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F'))
				cout<<"11";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
    else cout<<"0000";
	return 0;
}
