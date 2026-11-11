#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	string a1,a2;
	a1+=s1[0];
	a1+=s1[1];
	a2+=s2[0];
	a2+=s2[1];
	if(a1!=a2){
		cout<<"1000";
		return 0;
	}
	if(s1[2]<='C'){
		if(s2[2]>'C')cout<<"1100";
		else{
			if(abs(int(s1[2]-s2[2]))!=1)cout<<"1110";
			else cout<<"1111";
		}
	}else{
		if(s2[2]<='C')cout<<"1100";
		else cout<<"1111";
	}
	return 0;
} 
