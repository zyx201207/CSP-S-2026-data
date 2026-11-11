#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
string s1, c1, s2, c2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>c1>>s1>>c2>>s2;
	//cout<<c1<<s1<<c2<<s2;
	if(c1[0] == c2[0] && c1[1] == c2[1]) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	int se1 = (s1[0]-'0') *10 + (s1[1]-'0'), se2 = (s2[0]-'0')* 10 + (s2[1]-'0');
	int sa1 = s1[2] -'A'+1, sa2 = s2[2] -'A'+1;
	if(se1 == se2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((sa1 <= 3 && sa2 <=3) || (sa1 >=4 && sa2 >=4)){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(sa1 - sa2) == 1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
