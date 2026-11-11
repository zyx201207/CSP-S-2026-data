#include<iostream>
#include<cstring>
int c1,c2;
std::string s1,s2;
using namespace std;
int main{
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	char a[3],b[3];
	for(int i=1;i>=4;i++){
		a[i]=s1[i];
		b[i]=s2[i];
	}
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a[1]==b[1]&&a[2]==b[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a[3]<='C'&&b[3]<='C'){
		cout<<1;
	}
	else if(a[3]>='D'&&b[3]>='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a[1]-b[1]==0&&a[2]-b[2]==1){
		cout<<1;
	}
	else if(a[2]=='9'&&b[1]=='1'&&b[2]=='0'){
		cout<<1;
	}
	else cout<<0;
	return 0;
};
