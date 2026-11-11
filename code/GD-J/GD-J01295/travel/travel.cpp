#include<bits/stdc++.h>
using namespace std;
string r,r1,x,x1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>r1>>x>>x1;
	if(x==r){
		cout<<"1";
		if(r1[0]==x1[0]&&r1[1]==x1[1]){
			cout<<"1";
			if(((r1[2]>='A'&&r1[2]<='C')&&(x1[2]>='A'&&x1[2]<='C'))||((r1[2]>='D'&&r1[2]<='F')&&(x1[2]>='D'&&x1[2]<='F'))){
				cout<<"1";
				if((abs(r1[2]-x1[2])==1)||(r1[2]=='D'&&x1[2]=='F')||(x1[2]=='D'&&r1[2]=='F')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
			else{
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
