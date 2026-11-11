#include <bits/stdc++.h>
using namespace std;
int c_1,c_2;
string s_1,s_2;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2) cout<<"1";
	else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]) cout<<"1";
	else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	char cs12=s_1[2],cs22=s_2[2];
	if(cs12=='A'&&cs22=='B'){
		cout<<"1";
	}
	else if(cs12=='A'&&cs22=='C'){
		cout<<"1";
	}
	else if(cs12=='B'&&cs22=='C'){
		cout<<"1";
	}
	else if(cs12=='B'&&cs22=='A'){
		cout<<"1";
	}
	else if(cs12=='C'&&cs22=='A'){
		cout<<"1";
	}
	else if(cs12=='C'&&cs22=='B'){
		cout<<"1";
	}
	
	else if(cs12=='D'&&cs22=='F'){
		cout<<"1";
	}
	else if(cs12=='F'&&cs22=='D'){
		cout<<"1";
	}
	else {
		cout<<"0";
		cout<<"0";
		return 0;
	}
	if(cs12+1==cs22||cs12==cs22+1){
		if(cs12!='C'&&cs22!='D'){
			cout<<"1";
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	else{
		cout<<"0";
		return 0;
	}
	
	return 0;
}
