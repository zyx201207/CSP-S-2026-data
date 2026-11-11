#include<bits/stdc++.h>
using namespace std;
string c1,s1;//R
string c2,s2;//X
bool same_box=false,same_row=false,same_side=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string row1=s1.substr(0,2),row2=s2.substr(0,2);
	if(c1==c2) {
		same_box=true;
		cout<<"1";
	}
	else cout<<"0";
	if(same_box==1){
		if(row1==row2) {
			same_row=true;
			cout<<'1';
		}
		else cout<<'0';
	}
	else cout<<0;
	if(same_box==1 && same_row==1){
		if((s1[2]<='A' && s2[2]<='A') || (s1[2]>='D' && s2[2]>='D')) {
			same_side=true;
			cout<<"1";
		}
		else cout<<'0';
	}
	else cout<<"0";
	if(same_box==1 && same_row==1 && same_side==1){
		int a=s1[2]-'A',b=s2[2]-'B';
		if(a-b==1 || a-b==-1) cout<<"1";
		else cout<<'0';
	}
	else cout<<"0";
	return 0;
}
