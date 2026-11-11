#include <bits/stdc++.h>
using namespace std;
string d,b;
int a,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
    cin>>b;
    cin>>c;
    cin>>d; 

	//1
	if(a==c){
		cout<<1;
	}
	else{
		cout<<0;
	}
	int k;
	//2
	if(b[1]==d[1]&&b[0] == d[0]&&a==c){
		cout<<1;
		k = 1;
	}
	else{
		cout<<0;
		k=0;
	}
	//3
	if(b[2] == 'D' && d[2] == 'F' && k == 1){
		cout<<1;
	} 
	
	else if(b[2]<='C' && b[2]>='A'&&d[2]<='C' && d[2]>='A'){
		if(k==1){
			cout<<1;
		}
		else{
			cout<<0;
			k = 0;
		}
	}
	else{
		cout<<0;
		k = 0;
	}
	//4
	if(k==1){
		if(b[2] == d[2]+1||b[2] == d[2]-1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
}
