#include <bits/stdc++.h>
using namespace std;
string c1,c2;
string x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>x1>>c2>>x2;
	if(c1==c2){
		cout<<"1";
		if(x1[0]==x2[0] && x1[1]==x2[1]){
			cout<<"1";
			if((x1[2]<='c' && x2[2]<='c')||(x1[2])>'c' && x2[2]>'c'){
				cout<<"1";
				if(x1[2]-x2[2]==1 || x2[2]-x1[2]==1){
					cout<<"1";
				}else if(x1[2]+x2[2]=='D'+'F'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
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
