#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s,z;
	cin>>a>>s>>b>>z;
	if(a!=b){
		cout<<"0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else{
		cout<<"1";
	}
	if(s[0]==z[0]&&s[1]==z[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s[2]=='F'||s[2]=='D'){
		if(z[2]!='F'&&z[2]!='D'){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}else if(z[2]=='F'||z[2]=='D'){
		if(s[2]!='F'&&s[2]!='D'){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}else{
		cout<<"1";
	}
	if(s[2]=='A'){
		if(z[2]=='B'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else if(s[2]=='B'){
		if(z[2]=='C'||z[2]=='A'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else if(s[2]=='C'){
		if(z[2]=='B'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else if(s[2]=='D'){
		if(z[2]=='F'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else if(s[2]=='F'){
		if(z[2]=='D'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
