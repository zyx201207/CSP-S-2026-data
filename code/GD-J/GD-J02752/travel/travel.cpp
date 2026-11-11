#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,x2,y1,y2;
	cin>>x1>>x2>>y1>>y2;
	string a=x2.substr(0,2),b=y2.substr(0,2);
	char c=x2[2],d=y2[2];
	if(x1==y1){
		cout<<1;
		if(a==b){
			cout<<1;
			if(c>='A' && c<='C' && d>='A' && d<='C'){
				cout<<1;
				if((c=='A' && d=='C') || (c=='C' && d=='A')){
					cout<<0;
					return 0;
				}else{
					cout<<1;
					return 0;
				}
			}else if(c>='D' && c<='E' && d>'D' && d<'E'){
				cout<<1<<1;
				return 0;
			}else{
				cout<<0<<0;
				return 0;
			}
		}else{
			cout<<0<<0<<0;
			return 0;
		}
	}else{
		cout<<0<<0<<0<<0;
		return 0; 
	}
	return 0;
} 
