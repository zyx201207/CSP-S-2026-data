#include<bits/stdc++.h>
using namespace std;
string a,aa,b,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(aa[0]==bb[0] and aa[1]==bb[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(int(aa[2]-'A')<3 and int(bb[2]-'A')<3 or int(aa[2]-'A')>=3 and int(bb[2]-'A')>=3){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(int(aa[2]-'A')-int(bb[2]-'A'))==1){
		cout<<"1";
	}else cout<<"0";
	return 0;
}
