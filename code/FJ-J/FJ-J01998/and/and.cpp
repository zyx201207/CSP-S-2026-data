#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in",stdin);
	freopen("and.out",stdout);
	string c,d,a,b;
	cin>>a[2]>>c[3]>>b[2]>>d[3];
	if(a[1]==b[1]&&a[2]==b[2]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	int m=0;
	if(c[1]==d[1]){
		m=m+1;
	}
	if(c[2]==d[2]){
		m=m+1;
	}
	if(m==2){
		cout<<"1";
	}else{
		cout<<"000";
	}
	int o=0;
	string n;
	n='ABC';
	int v=6;
	for(int i=0;i<3;i++){
		if(c[3]==n[i]){
			o++;
		}else{
			v--;
		}
	}
	for(int i=0;i<3;i++){
		if(d[3]==n[i]){
			o++;
		}else{
			v--;
		}
	}
	if(o==2||v==0){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	int x=0;
	if(c[3]=='D'){
		if(d[3]=='F'){
			x=x+2;
		}
	}
	if(c[3]=='F'){
		if(d[3]=='D'){
			x=x+2;
	}
	if(x==2){
		cout<<"1";
	}
	}
	if(c[3]=='B'||d[3]=='B'){
		cout<<"1";
		return 0;
	}
	cout<<"0";
	return 0;
}