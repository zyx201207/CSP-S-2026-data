#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char ac1,ac2;
	char as1,as2,acc;
	
	char bc1,bc2;
	char bs1,bs2,bcc;
	
	cin>>ac1>>ac2>>as1>>as2>>acc>>bc1>>bc2>>bs1>>bs2>>bcc;
	int traina=(ac1-'0')*10+ac2-'0';
	int trainb=(bc1-'0')*10+bc2-'0';
	if(traina!=trainb){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	int pa=(as1-'0')*10+as2-'0';
	int pb=(bs1-'0')*10+bs2-'0';
	if(pa!=pb){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	int b=max((int)(bcc-'A'),(int)(acc-'A'));
	int a=min((int)(bcc-'A'),(int)(acc-'A'));
	if((a==0||a==1||a==2)&&(b==3||b==4)){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(abs(b-a)==1){
		cout<<"1";
	}
	else {
		cout<<"0";
	}
		
	return 0;
}
