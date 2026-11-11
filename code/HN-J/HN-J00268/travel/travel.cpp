#include <bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<'1';
		bool flag=true;
		for(int i=0;i<2;i++){
			if(c1[i]!=c2[i]){
				flag=false;
				break;
			}
		}
		if(flag==true){
			cout<<'1';
			if((c1[2]<='C'&&c2[2]<='C')||(c1[2]>'C'&&c2[2]>'C')){
				cout<<'1';
				if(abs(int(c1[2]-c2[2]))==1||(c1[2]=='D'&&c2[2]=='F')||(c1[2]=='F'&&c2[2]=='D')) cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else{
			cout<<"000";
		}
	}
	return 0;
} 
