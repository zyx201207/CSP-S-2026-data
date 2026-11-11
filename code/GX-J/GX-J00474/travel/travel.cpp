#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	vector<string> a;
	for(int i=0;i<4;i++){
		string b;
		cin>>b;
		a.push_back(b);
	}
	string b="0000";
	if(a[0]!=a[2]){
		cout<<"0000";
		return 0;
	}
	else{
		b[0]='1';
	}
	int l=0;
	string c=a[1],d=a[3];
	char e=c[2],f=d[2];
	if(c[1]==d[1]&&c[0]==d[0]){
		b[1]='1';
	}else{
		l=1;
	}
	
	if(((e>='D'&&f>='D') || (e<='C'&&f<='C')) && l==0){
		b[2]='1';
	}else{
		l=1;
	}
	
	if((max(e,f)+1==min(f,e)||max(e,f)-1==min(f,e))&& l==0){
		b[3]='1';
	}
	cout<<b;
	return 0;
}
