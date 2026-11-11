#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string s;
	int nn,mm;
	cin>>n;
	cin>>s;
	nn=((s[0]-'0')*100+(s[1]-'0')*10+(s[2]-'A'+1));
	cin>>m;
	cin>>s;
	mm=((s[0]-'0')*100+(s[1]-'0')*10+(s[2]-'A'+1));
	if(n==m){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(nn/10==mm/10){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((nn%10<=3&&mm%10<=3)||(nn%10>=4&&mm%10>=4)){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if((((nn%10)-(mm%10)==1||(mm%10)-(nn%10)==1)&&(mm%10)!=4&&(nn%10)!=4)||(((mm%10)==4||(nn%10)==4)&&((mm%10)==6||(nn%10)==6))){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
	}
