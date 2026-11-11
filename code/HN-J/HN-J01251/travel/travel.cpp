#include<bits/stdc++.h>
using namespace std;
int sn(string s){
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'==0){
			continue;
		}
		if(s[i]>='0'&&s[i]<='9'){
			sum+=s[i]-'0';
			sum*=10;
		}
	}
	return sum/10;
}
char sw(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]>='A'&&s[i]<='Z'){
			return s[i];
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string xa,xb,ya,yb,ans;
	cin>>xa>>xb>>ya>>yb;
	if(xa==ya){
		ans+='1';
		if(sn(xb)==sn(yb)){
			ans+='1';
		}else{
			ans+='0';
		}
		if(sn(xb)==sn(yb)&&((sw(xb)>='A'&&sw(yb)<='C'&&sw(xb)>='A'&&sw(yb)<='C')||(sw(xb)>='D'&&sw(yb)<='F'&&sw(xb)>='D'&&sw(yb)<='F'))){
			ans+='1';
		}else{
			ans+='0';
		}
		if(sn(xb)==sn(yb)&&((sw(xb)>='A'&&sw(yb)<='C'&&sw(xb)>='A'&&sw(yb)<='C')||(sw(xb)>='D'&&sw(yb)<='F'&&sw(xb)>='D'&&sw(yb)<='F'))){
			if(sw(xb)-'0'+1<='F'-'0'){
				if((sw(xb)-'0')+1==(sw(yb)-'0')){
					ans+='1';
				}
			}else if(sw(xb)-'0'-1>='A'-'0'){
				if((sw(xb)-'0')-1==(sw(yb)-'0')){
					ans+='1';
				}
			}
		}else if(sw(xb)==sw(yb)){
			if(sn(xb)+1<=18){
				if(sn(xb)+1==sn(yb)){
					ans+='1';
				}
			}else if(sn(xb)-1>=0){
				if(sn(xb)-1==sn(yb)){
					ans+='1';
				}
			}
		}else{
			ans+='0';
		}
	}else{
		cout<<"0000";
		return 0;
	}
	cout<<ans;
	return 0;
}
