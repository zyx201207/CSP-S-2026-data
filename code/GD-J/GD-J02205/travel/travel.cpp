#include<iostream>
#include<string>
#include<cmath>
using namespace std;


bool c[200005];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	string n1,n2,m1,m2;
	cin>>n1>>n2>>m1>>m2;
	if(n1==m1){
		cout<<1;
		if(n2[0]==m2[0]&&n2[1]==m2[1]){
			cout<<1;
			if((n2[2]>='A'&&n2[2]<='C'&&m2[2]>='A'&&m2[2]<='C')||(n2[2]<='F'&&n2[2]>='E'&&m2[2]<='F'&&m2[2]>='E')){
				cout<<1;
				if(abs(n2[2]-m2[2])==1){
					cout<<1;
				}else{
					cout<<0;
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
