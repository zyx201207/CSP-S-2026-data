#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,p1,c2,p2;
	char l1,l2;
	cin>>c1>>p1>>l1>>c2>>p2>>l2;
	if(c1==c2){
		cout<<1;
		if(p1==p2){
			cout<<1;
			if(((l1>='A'&&l1<='C')&&(l2>='A'&&l2<='C'))||((l1>='D'&&l1<='F')&&(l2>='D'&&l2<='F'))){
				cout<<1;
				if(abs(l2-l1)==1){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
