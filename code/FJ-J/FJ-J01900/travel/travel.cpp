#include<bits/stdc++.h>
using namespace std;
struct num{
	string cx;
	string pai="";
	string lei="";
}a[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		string s;
		cin>>a[i].cx>>s;
		a[i].pai+=s[0];
		a[i].pai+=s[1];
		a[i].lei+=s[2];
	}
	if(a[1].cx==a[2].cx){
		cout<<"1";
		if(a[1].pai==a[2].pai){
			cout<<"1";
			if(a[1].lei=="A"){
				if(a[2].lei=="B") cout<<"11";
				else if(a[2].lei=="C") cout<<"10";
				else cout<<"00";
			}
			else if(a[1].lei=="B"){
				if(a[2].lei=="A") cout<<"11";
				else if(a[2].lei=="C") cout<<"11";
				else cout<<"00";
			}
			else if(a[1].lei=="C"){
				if(a[2].lei=="A") cout<<"10";
				else if(a[2].lei=="B") cout<<"11";
				else cout<<"00";
			}
			else if(a[1].lei=="D"){
				if(a[2].lei=="E") cout<<"11";
				else cout<<"00";
			}
			else if(a[1].lei=="E"){
				if(a[2].lei=="D") cout<<"11";
				else cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
