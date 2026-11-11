#include<bits/stdc++.h>
using namespace std;
int sum1=0,sum2=0,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[2],s2[3],s3[2],s4[3];
	for(int i=0;i<2;i++){
		cin>>s1[i];
	}
	for(int i=0;i<3;i++){
		cin>>s2[i];
	}
	for(int i=0;i<2;i++){
		cin>>s3[i];
	}
	for(int i=0;i<3;i++){
		cin>>s4[i];
	}
	if(s2[2]>='A'&&s2[2]<='C') a=0;
	else a=1;
	if(s4[2]>='A'&&s4[2]<='C') b=0;
	else b=1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s3[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	if(s2[0]!=s4[0]||s2[1]!=s4[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(a!=b){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(a==0&&abs(s2[2]-s4[2])!=1){
		cout<<"0";
		return 0;
	} 
	cout<<"1";
	return 0;
}
