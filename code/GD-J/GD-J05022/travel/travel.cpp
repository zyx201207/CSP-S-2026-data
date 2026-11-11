#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	int s1,s2;
	char x,y;
	cin>>c1>>s1>>x>>c2>>s2>>y;
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if((x<='C'&&y<='C')||(x>'C'&&y>'C')){
				cout<<1;
				if(x-y==1||y-x==1){
					cout<<1;
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
