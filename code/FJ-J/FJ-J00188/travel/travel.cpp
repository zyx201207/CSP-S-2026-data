#include<bits/stdc++.h>
using namespace std;
string c,s,cn,sn;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cn>>sn;
	for(int i=0;i<c.size();i++){
		if(c[i]!=cn[i]){
			cout<<"0000";
			return 0;
		}
	}cout<<"1";
	int f=1;
	for(int i=0;i<s.size()-1;i++){
		if((i==0||i==1)&&s[i]!=sn[i]){
			cout<<"000";
			return 0;
		}
	}cout<<"1";
	if(s[2]<='C'&&sn[2]<='C'||s[2]>='D'&&sn[2]>='D'){
		cout<<"1";
		if(((s[2]+1)==sn[2])||((sn[2]+1)==s[2]))cout<<"1";
		else cout<<"0";
	}else cout<<"00";
	return 0;
}
