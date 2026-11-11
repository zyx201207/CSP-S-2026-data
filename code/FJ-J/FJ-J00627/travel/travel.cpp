#include<bits/stdc++.h>
using namespace std;
long long c1,c3;
string c2,c4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<"1";
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			cout<<"1";
			if((c2[c2.size()-1]<='C'&&c4[c4.size()-1]<='C')||(c2[c2.size()-1]>'C'&&c4[c4.size()-1]>'C')){
				cout<<"1";
				if(c2[2]+1==c4[2]||c2[2]-1==c4[2]){
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
