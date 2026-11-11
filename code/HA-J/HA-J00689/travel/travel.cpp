#include<bits/stdc++.h>
using namespace std;
int x,xx;
string s,ss,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>s>>xx>>ss;
	if(x != xx){//1 
		cout<<"0000"<<endl;
		return 0;
	}else{//1
		cout<<"1";
		a=s.substr(0,2);
		b=ss.substr(0,2);
		if(a == b){//2
			cout<<"1";
			if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(ss[2]=='A'||ss[2]=='B'||ss[2]=='C')){
				cout<<"1";
			}else if((s[2]=='D'||s[2]=='F')&&(ss[2]=='D'||ss[2]=='F')){
				cout<<"1";
			}else{
				cout<<"00";
				return 0;
			}
			//cout<<(int)s[2]-ss[2]<<endl;
			if(abs((int)s[2]-ss[2]) == 1){
				cout<<"1"<<endl;
			}else{
				cout<<"0"<<endl;
			}
		}else{
			cout<<"000";
			return 0;
		}
		
	}
	return 0;
}
