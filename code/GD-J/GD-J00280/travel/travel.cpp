//OK
#include<bits/stdc++.h>
using namespace std;
string c[2],s[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[0]>>s[0]>>c[1]>>s[1];
	if(c[0]!=c[1])cout<<"0000";//同厢 
	else{
		cout<<1;
		if(s[0][0]!=s[1][0]||s[0][1]!=s[1][1])cout<<"000";
		else{//同排
			cout<<1;
			if(s[0][2]>='A'&&s[0][2]<='C'){//同侧 
				if(s[1][2]>='A'&&s[1][2]<='C'){
					cout<<1;
					if(abs(s[1][2]-s[0][2])==1)cout<<1;
					else cout<<0;
					return 0;//相邻 
				}
				else cout<<"00";
			}
			else{
				//同侧且相邻 
				if(s[0][2]=='D'){
					if(s[1][2]=='F'){
						cout<<11;
						return 0;
					}
					else cout<<"00";
				}
				else if(s[0][2]=='F'){
					if(s[1][2]=='D'){
						cout<<11;
						return 0;
					}
					else cout<<"00";
				}
				return 0;
			}
		}
	}
	return 0;
} 
