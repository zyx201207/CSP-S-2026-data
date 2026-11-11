#include<bits/stdc++.h>
using namespace std;

string ca,cb,sa,sb;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca[0]!=cb[0] || ca[1]!=cb[1]){
		cout<<"0000";
		return 0;
	}
	if(sa[0]!=sb[0] || sa[1]!=sb[1]){
		cout<<"1000";
		return 0;
	}
	if(!((sa[2]<='C' && sb[2]<='C') || (sa[2]>='D' && sb[2]>='D'))){
		cout<<"1100";
		return 0;
	}
	if((sa[2]=='A' && sb[2]=='C') || (sa[2]=='C' && sb[2]=='A')){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
