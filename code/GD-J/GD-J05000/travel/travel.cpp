#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	string s1,s2;
	char d1,d2;
	for(int i=0;i<a2.length();i++){
		if(a2[i]>='A'&&a2[i]<='F'){
			d1=a2[i];
			continue;
		}
		s1+=a2[i];
	}
	for(int i=0;i<b2.length();i++){
		if(b2[i]>='A'&&b2[i]<='F'){
			d2=b2[i];
			continue;
		}
		s2+=b2[i];
	}
if(a1==b1){
	cout<<1;
	if(s1==s2){
		cout<<1;
		if((d1>='A'&&d1<='C')&&(d2>='A'&&d2<='C')){
			cout<<1;
			if((d1+1)==int(d2)||(d1-1)==int(d2)){
				cout<<1;
			}else{
				cout<<0;
				return 0;
			}
		}else if((d1>='D'&&d1<='F')&&(d2>='D'&&d2<='F')){
			cout<<1;
			if((d1+1)==int(d2)||(d1-1)==int(d2)){
				cout<<1;
			}else{
				cout<<0;
				return 0;
			}
		}else{
			cout<<0<<0;
			return 0;
		}
	}else{
		cout<<0<<0<<0;
		return 0;
	}
}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
