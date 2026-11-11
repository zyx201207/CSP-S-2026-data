#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int x1=((int)(s1[0]-'0'))*10+((int)(s1[1]-'0'));
		int x2=((int)(s2[0]-'0'))*10+((int)(s2[1]-'0'));
		if(x1==x2){
			cout<<"1";
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')){
				cout<<"1";
				if(abs((int)(s1[2]-s2[2]))==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}

