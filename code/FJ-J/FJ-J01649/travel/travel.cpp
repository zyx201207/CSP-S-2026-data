#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	cin>>a1>>a2>>b1>>b2;
	freopen("travel.out","w",stdout);
	if(a1!=b1){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<"1";
			if(b2[2]>='D'&&a2[2]>='D'){
				cout<<"11";
				return 0;
			}else if(b2[2]>='D'&&a2[2]<'D'){
				cout<<"00";
				return 0;
			}else if(b2[2]<'D'&&a2[2]>='D'){
				cout<<"00";
				return 0;
			}else{
				cout<<"1";
				if(b2[2]=='B'||a2[2]=='B'){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}
		}else{
			cout<<"000";
			return 0;
		}
	}
	return 0;
}
