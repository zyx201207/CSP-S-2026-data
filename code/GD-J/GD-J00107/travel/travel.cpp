#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<"1";
		string r=sr.substr(0,2),x=sx.substr(0,2);
		if(r==x){
			cout<<"1";
			char a=sr[2],b=sx[2];
			if((a<='C' && b<='C') || (a>='D' && b>='D')){
				cout<<"1";
				int n=a+0,m=b+0;
				if(abs(n-m)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
