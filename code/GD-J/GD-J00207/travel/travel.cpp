#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int x=(b[0]-'0')*100+(b[1]-'0')*10+b[2]-'A';
	int y=(d[0]-'0')*100+(d[1]-'0')*10+d[2]-'A';
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
	}
	if(x/10!=y/10){
		cout<<"000";
		return 0; 
	}
	else{
		cout<<"1";
	}
	if(x%10<3&&y%10<3){
		cout<<"1";
		if(abs(x%100-y%100)==1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else if(x%10>=3&&y%10>=3){
		cout<<"11";
	}
	else{
		cout<<"00";
		return 0;
	}
	return 0;
} 
