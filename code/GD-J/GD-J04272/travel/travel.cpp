#include<bits/stdc++.h>
using namespace std;
char c3[5],c4[5];
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	bool f=0;
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>c3[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>c4[i];
	}
	if(c1==c2) ans+='1';
	else{
		ans+='0';
	}
	if(c3[1]==c4[1] && c3[2]==c4[2]) ans+='1';
	else{
		ans+='0';
	}
	if('A'<=c3[3] && c3[3]<='C'){
		if('A'<=c4[3] && c4[3]<='C'){
			ans+='1';
			f=1;
		}
		else{
			ans+='0';
		}
	}
	else{
		if('D'<=c4[3]){
			ans+='1';
			f=1;
		}
		else ans+='0';
	}
	if(f==1){
		if(c3[3]==c4[3]+1 || c3[3]==c4[3]+1) ans+='1';
		else ans+='0';
	}
	else ans+='0';
	cout<<ans;
	return 0;
} 
