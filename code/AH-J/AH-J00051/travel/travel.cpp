#include<bits/stdc++.h>

using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	int a=(c1[0]-'0')*10+c1[1]-'0';
	int b1=(c2[0]-'0')*10+c2[1]-'0';
	int b2=c2[2]-'A'+1;
	int c=(c3[0]-'0')*10+c3[1]-'0';
	int d1=(c4[0]-'0')*10+c4[1]-'0';
	int d2=c4[2]-'A'+1;
	string out="0000";
	if(a==c)out[0]='1';
	else{
		cout<<out;
		return 0;
	}
	if(b1==d1)out[1]='1';
	else{
		cout<<out;
		return 0;
	}
	if((b2<=3&&d2<=3)||(b2>3&&d2>3))out[2]='1';
	else{
		cout<<out;
		return 0;
	}
	if(b2>3&&d2>3)out[3]='1';
	else if((b2==1&&d2==2)||(b2==2&&d2==3))out[3]='1';
	else{
		cout<<out;
		return 0;
	}
	cout<<out;
	return 0;
}
