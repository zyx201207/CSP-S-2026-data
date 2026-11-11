#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}
	else if(b[0]!=d[0] || b[1]!=d[1]){
		cout<<"1000";
	}
	else if((b[2]<='C' && d[2]>='D') || (d[2]<='C' && b[2]>='D')){
		cout<<"1100";
	}
	else if(!((b[2]=='A' && d[2]=='B') || (b[2]=='B' && d[2]=='C') || (b[2]=='D' && d[2]=='E') || (d[2]=='A' && b[2]=='B') || (d[2]=='B' && b[2]=='C') || (d[2]=='D' && b[2]=='E'))){
		cout<<"1110";
	} 
	else cout<<"1111";
	cout<<endl;
	return 0;
}
