#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e,f;
bool aa;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int cnt=0;
	
	for(int i=0;i<2;i++){
		if(a[i]==c[i]){
			cnt++;
		}
	}
	if(cnt==2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	cnt=0;
	for(int i=0;i<2;i++){
		if(b[i]==d[i]){
			cnt++;
		}
	}
	if(cnt==2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	e=b[2];
	f=d[2];
	if(e>="A"&&e<="C"&&f>="A"&&f<="C"){
		cout<<1;
	}
	else if(e>="D"&&e<="F"&&f>="D"&&f<="F"){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(e+"1"==f||f+"1"==e){
		aa=true;
	}
	if(e>="A"&&e<="C"&&f>="A"&&f<="C"&&aa){
		cout<<1;
	}
	else if(e>="D"&&e<="F"&&f>="D"&&f<="F"&&aa){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
