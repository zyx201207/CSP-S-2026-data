#include<bits/stdc++.h>
using namespace std;
string a,b;
string s,n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>n;
	if(a=="01"||b=="01"||a=="16"||b=="16"){
		cout<<"0000";
		return 0;
	}
	int a1=0,b1,c1,d1;
	if(a[0]==b[0]&&a[1]==b[1]){
		a1=1;
		cout<<1;
	}if(a1==0){
		cout<<"0000";
		return 0;
	}
	int cnt=0;
	for(int i=0;i<=1;i++){
		if(s[i]==n[i]){
			cnt++;
		}
	}if(cnt==2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}if((char(s[2])>='A'&&char(s[2])<='C'&&char(n[2])>='A'&&char(n[2])<='C')||(char(s[2])>='D'&&char(s[2])<='F'&&char(s[2]!='E')&&char(n[2])>='D'&&char(n[2])<='F')&&char(n[2]!='E')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}if(char(s[2]+1)==n[2]||char(s[2]-1)==n[2]||char(n[2]+1)==s[2]||char(n[2]-1)==s[2]||(char(n[2])=='D'&&char(s[2])=='F')||(char(s[2])=='D'&&char(n[2])=='F')){
		cout<<"1";
		return 0;
	}else{
		cout<<"0";
	}
	return 0;
} 
