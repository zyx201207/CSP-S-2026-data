#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			char a=s1[2],b=s2[2];
			if(a>='A' && a<='C' && b>='A' && b<='C'){
				cout<<"1";
				if(a+1==b || b+1==a) cout<<"1";
				else cout<<"0";
			}
			else{
				if(a>='D' && a<='F' && b>='D' && b<='F') 
					cout<<"11";
				else cout<<"00";
				
			}
		}
		else cout<<"000";
	}
	return 0;
} 
