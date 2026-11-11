#include<bits/stdc++.h>
using namespace std;
char x[5],y[5];
bool w(){
	if(x[2]<='C'&&y[2]<='C') return 1;
	if(x[2]>='D'&&y[2]>='D') return 1;
	return 0;
}
bool q(){
	if(x[2]=='A'&&y[2]=='B') return 1;
	if(x[2]=='B'&&(y[2]=='A'||y[2]=='C')) return 1;
	if(x[2]=='C'&&y[2]=='B') return 1;
	if(x[2]=='D'&&y[2]=='E') return 1;
	if(x[2]=='E'&&y[2]=='D') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;	
	cin>>a>>x>>b>>y;
	if(a==b){
		cout<<1;
		if(x[0]==y[0]&&x[1]==y[1]){
			cout<<1;
			if(w()){
				cout<<1;
				if(q()){
					cout<<1;
				}
				else cout<<"0";
			}
			else cout<<"00";	
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
