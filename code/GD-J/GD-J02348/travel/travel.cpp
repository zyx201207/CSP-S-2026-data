#include<bits/stdc++.h>
using namespace std;
int c1,c2,l1,l2,b1,b2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	l1=(s1[0]-'0')*10+(s1[1]-'0');
	l2=(s2[0]-'0')*10+(s2[1]-'0');
	b1=s1[2];
	b2=s2[2];
	if(c1!=c2){
		cout<<"0000";
	}else{
		if(l1!=l2){
			cout<<"1000";
		}else{
			if(b1>b2){
				swap(b1,b2);
			}
			if(b1<='C'&&b2>='D'){
				cout<<"1100";
			}else{
				if(b2-b1>1){
					cout<<"1110";
				}else{
					cout<<"1111";
				}
			}
		}
	}
	return 0;
}
