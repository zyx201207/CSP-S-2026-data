#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string st,sd,ct,cd;
	cin>>ct>>st>>cd>>sd;
	if(ct==cd){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(st[0]==sd[0]&&st[1]==sd[1]){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	if((st[2]<=67&&sd[2]<=67)||(st[2]>67&&sd[2]>67)){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(st[2]-sd[2])==1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
