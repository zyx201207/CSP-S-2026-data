#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int s1=0,s2=0,s3=0,s4=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		s1=1;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		s2=1;
	}
	if(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C'){
		s3=1;
	}
	if(b[2]-d[2]==1&&s3==1||b[2]-d[2]==-1&&s3==1){
		s4=1;
	}
	cout<<s1<<s2<<s3<<s4;
} 
