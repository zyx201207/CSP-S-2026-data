#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",std);
	freopen("travel.out","w",std);
	string a,b,c,d;
	
	
	cin>>a>>b>>c>>d;
	
	
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]){
			cout<<"1";
			if(b[1]==d[1]){
				cout<<"1";
				if(b[2]+1==d[2] || b[2]-1==d[2]){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"0";
			}
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"0000";
	}
	
	
	return 0;	
} 
