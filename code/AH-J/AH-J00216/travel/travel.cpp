#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string aa,bb;
	char a,b,c,d;
	cin>>a>>b>>aa;
	cin>>c>>d>>bb;
	if(a==c&&b==d){
		cout<<"1";
	}else{ cout<<"0000";return 0;}
	if(aa[0]==bb[0]&&aa[1]==bb[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(aa[2]=='D'&&bb[2]=='F'){
		cout<<"11";
	}	
	else if(aa[2]=='F'&&bb[2]=='D'){
		cout<<"11";
	}
	else if(aa[2]=='B'&&bb[2]=='A'){
		cout<<"11";
	}	
	else if(aa[2]=='B'&&bb[2]=='C'){
		cout<<"11";
	}
	else if(aa[2]=='A'){
		if(bb[2]=='B'||bb[2]=='C'){
			cout<<'1';
			if(bb[2]=='B'){
				cout<<'1';
			}
			else cout<<'0';
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	else if(aa[2]=='C'){
		if(bb[2]=='B'||bb[2]=='A'){
			cout<<'1';
			if(bb[2]=='B'){
				cout<<'1';
			}
			else cout<<'0';
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	return 0;
}
