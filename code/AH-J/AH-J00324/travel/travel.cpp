#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		 cout<<0;
		 f=1;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&f==0){
		cout<<1;
	}else{
		cout<<0;
		f=1;
	}	
	if(((char(b[2])>='D'&&char(d[2])>='D')||(char(d[2])<='C'&&char(b[2])<='C'))&&f==0){
		cout<<1;
	}else{
		cout<<0;
		f=1;
	}
	if(abs(d[2]-b[2])==1&&f==0){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
