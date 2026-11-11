#include<bits/stdc++.h>
using namespace std;
string c,cc,s,ss;
int f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>cc>>s>>ss;
	if(c[0]==s[0]&&c[1]==s[1]){
		cout<<1;
		if(cc[0]==ss[0]&&cc[1]==ss[1]){
			cout<<1;
			if(cc[2]=='D'&&ss[2]=='F'){
				cout<<1;
				f=1;
			}
			else if(cc[2]-'A'+1<=3&&ss[2]-'A'+1<=3){
				cout<<1;
				f+=2;
			}
			else{
				cout<<"00";
				return 0;
			}
			if(f==1){
				cout<<9;
				cout<<1;
				return 0;
			}
			else{
				if(abs((cc[2]-'A')-(ss[2]-'A'))<=1){
					cout<<1;
					return 0;
				}
				
			}	
			cout<<0;
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
