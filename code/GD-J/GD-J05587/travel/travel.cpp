#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0] && b[1]==d[1]){
			cout<<1;
			if((b[2]=='C' && d[2]=='D') || (b[2]=='D' && d[2]=='C')){
				cout<<0;
				f=1;
			}
			else cout<<1;
		}
		else{
			f=1;
			cout<<"00";
		}
	}
	else{
		cout<<"000";
	}
	if(f!=1 && abs((b[2]-'A')-(d[2]-'A'))==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
