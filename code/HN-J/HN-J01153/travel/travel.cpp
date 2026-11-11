#include<iostream>
using namespace std;
string s,s1,s2,s3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	if(s==s2){
		cout<<1;
	}else{
		cout<<0;
	}
	//string t,t1;
	int f1=1,f=0;
	if(s==s2){
		
		for(int i=0;i<=1;i++){
			if(s1[i]!=s3[i]){
				f1=0;
				cout<<0;
				break;
			}
		}
		if(f1==1){
			f=1;
			cout<<1;
		}
	}else{
		cout<<0;
	}
	int f2=0;
	if(f==1){
		if(s1[2]=='A'&&s3[2]=='B'||s1[2]=='A'&&s3[2]=='C'){
			cout<<1;
		}else if(s1[2]=='B'&&s3[2]=='C'||s1[2]=='B'&&s3[2]=='A'){
			cout<<1;
		}else if(s1[2]=='C'&&s3[2]=='B'||s1[2]=='C'&&s3[2]=='A'){
			cout<<1;
		}else if(s1[2]=='D'&&s3[2]=='E'){
			cout<<1;
		}else if(s1[2]=='E'&&s3[2]=='D'){
			cout<<1; 
		}else{
			f2=1;
			cout<<0;
		}
	}else{
		cout<<0;
		f2=1;
	}
	if(f2==0){
		if(s1[2]=='A'&&s3[2]=='B'){
			cout<<1;
		}else if(s1[2]=='B'&&s3[2]=='C'||s1[2]=='B'&&s3[2]=='A'){
			cout<<1;
		}else if(s1[2]=='C'&&s3[2]=='B'){
			cout<<1;
		}else if(s1[2]=='D'&&s3[2]=='E'){
			cout<<1;
		}else if(s1[2]=='E'&&s3[2]=='D'){
			cout<<1; 
		}else{
			//f2=1;
			cout<<0;
		}
	}else{
		cout<<0;
	}
//	cout<<s1[2]<<" "<<s3[2];
	return 0;
}
