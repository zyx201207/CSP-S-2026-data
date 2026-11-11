#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a!=b){
		cout<<"0000";
	} 
	else{
		cout<<1;
		if(c[0]==d[0] && c[1]==d[1]){
			cout<<1;
			if(c[2]=='C' && d[2]=='D'){
				cout<<"00";
			}
			else if(c[2]=='D' && d[2]=='C'){
				cout<<"00";
			}
			else{
				cout<<1;
				if(c[2]=='D' || d[2]=='D'){
					if(d[2]=='F' || c[2]=='F'){
						cout<<1;
					}
					else{
						cout<<"00";
					}
				}
				else if(c[2]=='F' || d[2]=='F'){
					cout<<"00";
				}
				else{
					if(abs(c[2]-d[2])==1){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
			}
		}
		else{
			cout<<"000";
		}
	}
	return 0;	
} 
