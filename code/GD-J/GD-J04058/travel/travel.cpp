#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<"1";
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			cout<<"1";//同一排 
			char a=sr[2],b=sx[2];
			if((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='F'&&b<='D'&&b<='F')){
				cout<<"1";//同一侧 
				if(a>='A'&&a<='C'&&b>='A'&&b<='C'){
					if(abs(a-b)==1)cout<<"1";
					else cout<<"0";
				}
				else{
					if(abs(a-b)==2)cout<<"1";
					else cout<<"0";
				}
				return 0; 
			}
			else{
				cout<<"00";//不在同一排不可能相邻 
				return 0;
			}
		}
		else{
			cout<<"000";//不在同一排全部不满足
			return 0; 
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
