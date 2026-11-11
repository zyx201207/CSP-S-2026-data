#include<bits/stdc++.h>
using namespace std;
int a,b;
string q,w;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>q>>b>>w;
	if(a==b){
		cout<<1;
		if((q[0]-'0')*10+(q[1]-'0')==(w[0]-'0')*10+(w[1]-'0')){
			cout<<1;
			if(((q[2]-'A')<=2 && (w[2]-'A')<=2)||((q[2]-'A')>2 && (w[2]-'A')>2)){
				cout<<1;
				if(q[2]-w[2]==1 || w[2]-q[2]==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				for(int i=1;i<=2;i++){
					cout<<0;
				}
			}
		}
		else{
			for(int i=1;i<=3;i++){
				cout<<0;
			}
		}
	}
	else{
		for(int i=1;i<=4;i++){
			cout<<0;
		}
	}
	return 0;
} 
