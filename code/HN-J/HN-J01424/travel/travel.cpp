#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int c1,c2;
int shu1,shu2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int n=s1.size(),m=s2.size();
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			shu1+=shu1*10+(s1[i]-'0');
		}
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			shu2+=shu2*10+(s2[i]-'0');
		}
	}
	if(shu1==shu2) cout<<"1";
	else{
		cout<<"000";
		return 0;	
	}
	if(s1[n-1]<='C'&&s2[m-1]<='C'){
		cout<<"1";
	}else{
		if(s1[n-1]>='D'&&s2[m-1]>='D'){
			cout<<"1";
		}else {
			cout<<"00";
			return 0;
		}
	}
//	cout<<shu1<<" "<<shu2;
	if(s1[n-1]=='A'&&s2[m-1]=='C'){
		cout<<"0";
	}else{
		if(s1[n-1]=='C'&&s2[m-1]=='A'){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}
	return 0;
}
