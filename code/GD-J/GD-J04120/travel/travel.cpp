#include<bits/stdc++.h>
using namespace std;
string s,ss,t,tt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>ss>>t>>tt;
	if(s!=t){
		cout<<"0000";
	}
	else{
		if(ss[0]==tt[0]&&ss[1]==tt[1]){
			if(ss[2]>='A'&&ss[2]<='C'&&tt[2]>='A'&&tt[2]<='C'){
				if(ss[2]==(tt[2]-1)||(ss[2]-1)==tt[2]){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else if((ss[2]=='D'||ss[2]=='F')&&(tt[2]=='D'||tt[2]=='F')){
				if((ss[2]=='D'&&tt[2]=='F')&&(ss[2]=='F'&&tt[2]=='D')){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
