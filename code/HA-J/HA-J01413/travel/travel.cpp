#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
    }
    if(s1[1],s1[2] == s2[1],s2[2]){
    	cout<<1;
	}else{
		cout<<0;
	}
	if(s1[3]== 'A' or 'B' or 'C' and s2[3]=='A' or 'B' or 'C' or s1[3]== 'D' or 'F' or s2[3]== 'D' or 'F'){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1[3]*s2[3]== 'AB' or 'BC' or 'DF'){
		cout<<1;
	}else{
		cout<<0;
	}
}
