#include<bits/stdc++.h>
using namespace std;
int a,b;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();cout.tie();
	cin>>c1>>s1>>c2>>s2;
	a=(s1[0]-'0')*10+s1[1];
	b=(s2[0]-'0')*10+s2[1];
	if(!(c1==c2)){
		cout<<"0000";
	}else{
		cout<<"1";
		if(!(a==b)){
			cout<<"000";
		}else{
			cout<<"1";
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(!(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
					cout<<"00";
				}else{
					cout<<"1";
					if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
						cout<<"0";
					}else if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}
			}else{
				if(!(s2[2]=='D'||s2[2]=='F')){
					cout<<"00";
				}else{
					cout<<"1";
					if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
						cout<<"0";
					}else if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}
			}
		}
	}
	return 0;
}
