#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a;
	string b;
	int c;
	string d;
	cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0] && b[1]==d[1]){
			if(b[2]==d[2]){
				cout<<"1110";
			}else{
				cout<<"1111";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
} 
