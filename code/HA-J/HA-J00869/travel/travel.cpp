#include<bits/stdc++.h>
using namespace std;
string a,b,aw,bw,pa,pb;
int ta,tb;
bool f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>aw>>a>>bw>>b;
	
	if(a[0]==0){
		ta=a[1]-'A'+1;
	}
	if(b[0]==0){
		tb=b[1]-'A'+1;
	}
	
	if(aw==bw){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	pa=a[0]+a[1],pb=b[0]+b[1];
	if(pa==pb){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	if(a[2]<='C'&&b[2]<='C'&&pa==pb){
		cout<<"1";
	}else if(a[2]>'C'&&b[2]>'C'&&pa==pb){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	if(a[2]=='C'&&b[2]=='D' || a[2]=='D'&&b[2]=='C'){
		f=0;
	}
	if(pa==pb&&abs(a[2]-b[2])==1 && f==1){
		cout<<"1";
	}else if(a[2]==b[2]&&abs(ta-tb)==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
