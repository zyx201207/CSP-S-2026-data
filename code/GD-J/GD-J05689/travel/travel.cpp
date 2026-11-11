#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a[3]=0;
	string b[3]=0;
	for(int i=0;i<2;i++){
		cin>>a[i]>>b[i];
	}
	if(a[0]==a[1]){
		cout<<1;
		if(b[0][0]==b[1][0]&&b[0][1]==b[1][1]){
			cout<<1;
			if(b[0][2]<=67&&b[1][2]<=67||b[0][2]<=70&&b[1][2]<=70){
				cout<<1;
				if(b[0][2]==b[1][2]+1||b[0][2]==b[1][2]-1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<00;
			}
		}
		else{
			cout<<000;
		}
	}
	else{
		cout<<0000;
	}
}
