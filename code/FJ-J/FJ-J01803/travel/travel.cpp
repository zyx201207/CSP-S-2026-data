#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[3],s1[3],c2[3],s2[3];
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[1]==c2[1]&&c1[0]==c2[0])cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout << 1;
	else{
		cout << "000";
		return 0;
	}
	int zuo1=s1[2]-'A'+1;
	int zuo2=s2[2]-'A'+1;
	if(zuo1==6)zuo1=5;
	if(zuo2==6)zuo2=5;
	bool zuo1xd3=(zuo1<=3);
	bool zuo2xd3=(zuo2<=3);
	if(zuo1xd3==zuo2xd3){
		cout << 1;
	}else{
		cout << "00";
		return 0;
	}
	if(zuo1-zuo2==1||zuo2-zuo1==1){
		cout << 1;
	}else cout << 0;
	
	return 0;
}
