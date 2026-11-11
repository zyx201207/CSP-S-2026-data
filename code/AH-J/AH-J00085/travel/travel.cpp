#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2;
	char a3,b3;
	cin>>a1>>a2>>a3>>b1>>b2>>b3;
	if(a1==b1){
		cout<<"1";
		if(a2==b2){
			cout<<"1";
			if((a3<'D')==(b3<'D')){
				cout<<"1";
				if((abs(a3-b3)==1) || (a3=='D'&&b3=='F') || (a3=='F'&&b3=='D')){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
