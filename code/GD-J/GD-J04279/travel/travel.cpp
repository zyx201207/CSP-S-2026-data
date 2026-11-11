#include<iostream>
using namespace std;

string a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<1;
		if(c[0]==d[0]&&c[1]==d[1]){
			cout<<1;
			if(c[2]<='C'&&d[2]<='C'){
				cout<<1;
				if((c[2]=='A'&&d[2]=='C')||(c[2]=='C'&&d[2]=='A')){
					cout<<0;
				}else{
					cout<<1;
				}
			}else if(c[2]>='D'&&d[2]>='D'){
				cout<<1<<1;
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
