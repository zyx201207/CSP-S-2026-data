#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int f1=0,f2=1,f3=0;
	if(c1==c2){
		f1=1;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			f2=0;
		}
	}
	int a=0,b=0; 
	for(int i='A';i<='C';i++){
		if(s1[2]==i){
			a=1;
		}
		if(s2[2]==i){
			b=1;
		}
	}
	if(s1[2]=='D'&&s2[2]=='F'){
		a=1;
		b=1;
	}
	if(s1[2]=='F'&&s2[2]=='D'){
		a=1;
		b=1;
	}
	if(s1[2]=='A'&&s2[2]=='B'){
		f3=1;
		//cout<<f3;
	}
	if(s1[2]=='B'&&s2[2]=='A'){
		f3=1;
	}
	if(s1[2]=='B'&&s2[2]=='C'){
		f3=1;
	}
	if(s1[2]=='C'&&s2[2]=='B'){
		f3=1;
	}
	if(s1[2]=='D'&&s2[2]=='F'){
		f3=1;
	}
	if(s1[2]=='F'&&s2[2]=='D'){
		f3=1;
	}
	//cout<<f1<<" "<<f2<<" "<<f3<<" "<<a<<" "<<b<<endl;
	if(f1==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(f2==1&&f1==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(f1==1&&f2==1&&a==1&&b==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(f1==1&&f2==1&&f3==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
