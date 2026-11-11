#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//cin>>c1>>s1>>c2>>s2;
	bool cx=false;
	bool typ=false;
	//int lenc1=c1.length();
	//int lens1=s1.length();
	//int lenc2=c2.length();
	//int lens2=s2.length();
	for(int i=0;i<2;i++){
		if(c1[i]==c2[i]){
			cx=true;
		}else{
			cx=false;
		}
	} 
	if(cx){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]==s2[i]){
			typ=true;
		}else{
			typ=false;
		}
	}
	if(typ)cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s1[2]>='A'&&s1[2]<='C' && s2[2]>='A'&&s2[2]<='C' || s1[2]>='D'&&s1[2]<='F' && s2[2]>='D'&&s2[2]<='F'){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='B' || s1[2]=='B'&&s2[2]=='C' || s1[2]=='D'&&s2[2]=='F'){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
