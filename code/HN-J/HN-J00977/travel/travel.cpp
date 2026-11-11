#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c3,c2,c4;
	char a1,a2;
	cin>>c1>>c2>>a1>>c3>>c4>>a2;
	if(c1==c3){
		cout<<1;
		if(c2==c4){
			cout<<1;
			if(a1<='C'&&a2<='C'&&a1>='A'&&a2>='A'){
				cout<<1;
				if(abs(c2-c3)==1){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else if(a1<='F'&&a2<='F'&&a1>='D'&&a2>='D'){
				cout<<1;
				if(abs(c2-c3)==1){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
	
}
