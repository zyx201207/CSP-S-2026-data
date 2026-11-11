#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	bool flag = false;
	if(s1[0] == s2[0]&&s1[1] == s2[1]){
		cout<<1;
		flag = 1;
	}
	else{
		cout<<0;
	}
	
	bool flaag = false;
	if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]>='A'&&s2[2]<='F')){
		if(flag == 1){
			cout<<1;
			flaag = 1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	
	
	if(s2[2] == 'F'){
		s2[2] = 'E';
	}
	if(s1[2] == 'F'){
		s1[2] = 'E';
	}
	int x = abs(int(s2[2] - s1[2]));
	if(s1[1] == s2[1]&&s1[0] == s2[0]&&x == 1){
		if(flaag){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
}
