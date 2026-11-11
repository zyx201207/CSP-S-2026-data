#include<bits/stdc++.h>
using namespace std;
string x,y,m,n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>m>>y>>n;
	if(x[0]==y[0]&&x[1]==y[1]) ;
	else{
		cout<<"0000";
		return 0;
	}
	if(m[0]!=n[0]||m[1]!=n[1]){
		cout<<"1000";
		return 0;
	}
	if((m[2]=='A'&&n[2]!='B'&&n[2]!='C')||(m[2]=='B'&&n[2]!='A'&&n[2]!='C')||(m[2]=='C'&&n[2]!='B'&&n[2]!='A')||(m[2]=='D'&&n[2]!='E')||(m[2]=='E'&&n[2]!='D')){
//		cout<<m[2]<<endl<<n[2]<<endl;
		cout<<"1100";
		return 0;
	}
	if((m[2]=='A'&&n[2]=='B')||(m[2]=='B'&&n[2]=='A')||(m[2]=='B'&&n[2]=='C')||(m[2]=='C'&&n[2]=='B')||(m[2]=='D'&&n[2]=='F')||(m[2]=='F'&&n[2]=='D')) {
		cout<<"1111";
		return 0;
	}	
	cout<<"1110";
	return 0;
} 
