#include<iostream>
#include<cmath>
using namespace std;
int c1,l1,c2,l2;
char s1,s2;
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>l1>>s1>>c2>>l2>>s2;
	if(c1==c2){
		cout<<1;
		if(l1==l2){
			cout<<1;
			if((s1<='C' && s2<='C')){
				cout<<1;
				if(abs(s1-s2)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(s1>='D' && s2>='D'){
				cout<<11;
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
