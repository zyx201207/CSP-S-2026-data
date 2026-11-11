#include <bits/stdc++.h> 
using namespace std;
int main(){	
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	int a1,a2;
	string a3,a4;
	cin>>a1>>a3>>a2>>a4;
	if(a1==a2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a3[1]==a4[1]&&a4[0]==a3[0]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((a3[2]=='D'&&a4[2]=='F')||(a3[2]=='F'&&a4[2]=='D')||(a3[2]=='C'&&a4[2]=='B')||(a3[2]=='B'&&a4[2]=='C')||(a3[2]=='B'&&a4[2]=='A')||(a3[2]=='A'&&a4[2]=='B')){
		cout<<11;
		return 0;
	}else if((a3[2]=='A'&&a4[2]=='C')||(a3[2]=='C'&&a4[2]=='A')){
		cout<<10;
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
