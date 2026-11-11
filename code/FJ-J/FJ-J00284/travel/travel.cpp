#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
bool check(char a,char b){
	return (a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='F'&&b>='D'&&b<='F');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<1;
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			cout<<1;
			if(check(sr[2],sx[2])){
				cout<<1;
				int a=(int)max(sr[2],sx[2]),b=(int)min(sx[2],sr[2]);
				if(a-b==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}
			else{
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
