#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string aa,bb;
	int a,b;bool f[5]={};	
	cin>>a>>aa>>b>>bb;	
	int x=int(aa[0])-48+int(aa[1])-48;
	int y=int(bb[0])-48+int(bb[1])-48;
	if(a==b){
		cout<<'1';
		f[0]=1;
	}
	else cout<<'0';	
	if(x==y&&f[0]){
		cout<<'1';
		f[1]=1;
	}
	else cout<<'0';
	if(aa[2]=='A'&&f[1]){
		if(bb[2]=='B'||bb[2]=='C'){
			cout<<'1';f[2]=1;
		}else cout<<'0';
	}if(!f[2]&&aa[2]=='B'&&f[1]){
		if(bb[2]=='A'||bb[2]=='C'){
			cout<<'1';f[2]=1;
		}else cout<<'0';
	}if(!f[2]&&aa[2]=='C'&&f[1]){
		if(bb[2]=='A'||bb[2]=='B'){
			cout<<'1';f[2]=1;
		}else cout<<'0';
	}if(!f[2]&&aa[2]=='D'&&f[1]){
		if(bb[2]=='E'){
			cout<<'1';f[2]=1;f[3]=1;
		}else cout<<'0';
	}if(!f[2]&&aa[2]=='E'&&f[1]){
		if(bb[2]=='D'){
			cout<<'1';f[2]=1;f[3]=1;
		}else cout<<'0';
	}if(!f[2]) cout<<'0';
	if(f[3])cout<<"1";
	else{
		if(f[2]){
			if(bb[2]=='B'){
				cout<<'1';
			}else if(aa[2]=='B'){
				cout<<'1';
			}else cout<<'0';
		}else cout<<'0';
	}
	return 0;
}
