#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,x;
	string m,y;
	cin>>n>>m>>x>>y;
	if(n==x){
		cout<<"1";
		if(m[0]==y[0]&&m[1]==y[1]){
			cout<<"1";
			if((m[2]!='D'&&y[2]!='C')||(m[2]!='C'&&y[2]!='D')){
				cout<<"00";
				return 0;
			}
			if(abs(m[2]-y[2])==1){
				cout<<"11";
				return 0;
			}else if(abs(m[2]-y[2])>=4){
				cout<<"00";
				return 0;
			}
			int f=1;
			if(m[2]=='B'&&y[2]=='D'){
				f=0;
			}if(m[2]=='D'&&y[2]=='B'){
				f=0;
			}if(m[2]=='C'&&y[2]=='E'){
				f=0;
			}if(m[2]=='E'&&y[2]=='C'){
				f=0;
			}
			if(f==0){
				cout<<"00";
			}else{
				cout<<"10";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
