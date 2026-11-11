#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;
	string a2,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
		if(a2[0]==b2[0] && a2[1]==b2[1]){
			cout<<1;
			if((a2[2]>='D' && b2[2]>='D') || (a2[2]<'D' && b2[2]<'D')){
				cout<<1;
				if(abs(a2[2]-b2[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
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
