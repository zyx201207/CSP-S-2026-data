#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2],s1[3],c2[2],s2[3];
	cin>>c1>>s1>>c2>>s2;
	int m=0,n=0;
	for(int i=0;i<2;i++){
		if(c1[i]==c2[i]){
			m++;
		}
	}
	if(m==2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]==s2[i]){
			m++;
		}
	}
	if(m==4){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1[2]<'D'&&s2[2]<'D'&&m==4){
		m++;
		cout<<1;
	}
	else if(s1[2]>'C'&&s2[2]>'C'&&m==4){
		m++;
		cout<<1;
	}
	else{
		cout<<0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]==s2[i]){
			n++;
		}
	}
	if(abs(s1[2]-s2[2])<=1){
		n++;
	}
	if(m==5&&n==3){
		cout<<1;
	}
	else{
		m=0;
		cout<<0;
	}
	return 0;
}
