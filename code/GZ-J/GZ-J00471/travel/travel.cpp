//GZ-J00471	遵义市第十二中学	何嘉欢 
#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	cin>>a>>c>>b>>d;
	//1
	if(a==b)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	//2
	if(c[0]==d[0]){
		if(c[1]==d[1])cout<<"1";
		else{
			cout<<"000";
			return 0;
		}
	}
	//3
	if((c[2]=='A'&&d[2]=='B')||(c[2]=='A'&&d[2]=='C')||(c[2]=='B'&&d[2]=='A')||(c[2]=='B'&&d[2]=='C')||(c[2]=='C'&&d[2]=='B')||(c[2]=='C'&&d[2]=='A')||(c[2]=='D'&&d[2]=='F')||(c[2]=='F'&&d[2]=='D'))cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	//4
	if((c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='A')||(c[2]=='B'&&d[2]=='C')||(c[2]=='C'&&d[2]=='B')||(c[2]=='D'&&d[2]=='F')||(c[2]=='F'&&d[2]=='D')){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 

