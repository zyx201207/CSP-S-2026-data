//GZ-J00162 遵义市第十二中学 田家锜 
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>c>>d;
	int l=0;
	if(a==c){
		cout<<1;
		l=1;
	}else{
		cout<<0;
	}
	string e=b.substr(0,2);
	string f=d.substr(0,2);
	int g=0;
	if(l&&(e==f)){
		cout<<1;
		g=1;
	}else{
		cout<<0;
	}
	string h=b.substr(2,1);
	string i=d.substr(2,1);
	char j=h[0];
	char k=i[0];
	if(g&&l){
		if((j=='D'&&k=='F')||(j=='F'&&k=='D')){
			cout<<11;
			return 0;
		}else if(j<='C'&&j>='A'&&k<='C'&&k>='A'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(l&&g&&((j=='A'&&k=='B')||(j=='B'&&k=='C')||(k=='A'&&j=='B')||(k=='B'&&j=='C'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
