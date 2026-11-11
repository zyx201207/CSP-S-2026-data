#include <bits/stdc++.h>
using namespace std;
int a,b;
string aa,bb,R,X;
char R3,X3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	R=aa[0]+aa[1];
	X=bb[0]+bb[1];
	R3=aa[2];
	X3=bb[2];
	if(a!=b){
		for(int i=0;i<4;i++){
			cout<<0;
		}
	}
	else{
		cout<<1;
		if(R!=X){
			for(int i=0;i<3;i++){
				cout<<0;
			}
		}
		else{
			cout<<1;
			if(!((('A'<=R3&&R3<='C')&&('A'<=X3&&X3<='C'))||(('D'<=R3&&R3<='E')&&('D'<=X3&&X3<='E')))){
				for(int i=0;i<2;i++){
					cout<<0;
				}
			}
			else{
				cout<<1;
				if(abs(R3-X3)==1) cout<<1; 
				else cout<<0;
			}
		}
	}
	return 0;
}

