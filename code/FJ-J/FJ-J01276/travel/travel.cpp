#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
map<char,int>mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['E']=2;
	if(cr==cx){
		cout<<"1";
		if(sr.substr(0,2)==sx.substr(0,2)){
			cout<<"1";
			if(mp[sr[2]]==mp[sx[2]]){
				cout<<"1";
				if(sr[2]==sx[2]+1||sx[2]==sr[2]+1){
					cout<<"1";
				}
				else{
					cout<<"0";
				} 
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
