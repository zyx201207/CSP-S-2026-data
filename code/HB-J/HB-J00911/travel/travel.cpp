#include<bits/stdc++.h>
using namespace std;
char b[20],d[20];
int main(){
	freopen("travel.in","r",stdin);
	//freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,c;
	cin>>a;
	for(int i=1;i<=3;i++){
		cin>>b[i];
	}
	cin>>c;
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	if(a==c){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(b[1]==d[1]&&b[2]==d[2]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(b[1]==d[1]&&b[2]==d[2]){
		if(b[3]-1==d[3]||d[3]-1==b[3]){
			if(b[3]=='D'&&d[3]=='C'){
				cout<<0<<0;
			}
			if(b[3]=='C'&&d[3]=='D'){
				cout<<0<<0;
			}else{
				cout<<1<<1;
			}
		}
	}
	if(b[3]=='A'&&d[3]=='C'){
		cout<<1<<0;
	}
	if(b[3]=='C'&&d[3]=='A'){
		cout<<1<<0;
	}
	return 0;
}
