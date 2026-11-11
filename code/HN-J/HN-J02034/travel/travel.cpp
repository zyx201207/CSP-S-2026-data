#include <bits/stdc++.h>
#define int long long
using namespace std;
string a1,a2,a3,a4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>a3>>a4;
	int f1=0;
	if(a1[0]==a3[0]&&a1[1]==a3[1]){
		cout<<1;	
		f1=1;	
	}
	else{
		cout<<0;
	}
	
	if(a2[0]==a4[0]&&a2[1]==a4[1]&&a1[0]==a3[0]&&a1[1]==a3[1]){
		cout<<1;
		f1=1;		
	}
	else{
		cout<<0;
		f1=0;
	}
	int f=0;
	if(f1==1){
		if(a2[2]=='C'||a2[2]=='D'||a4[2]=='C'||a4[2]=='D'&&f1==1){
			if(a2[2]=='C'){
				if(a4[2]=='B'||a4[2]=='A'){
					cout<<1;
					f=1;
				}
				else{
					cout<<0;
				}
			}
		}
		else if(a2[2]=='D'){
			if(a4[2]=='F'){
				cout<<1;
				f=1;
			}
			else{
				cout<<0;
			}
		}
		
		else if(a4[2]=='C'){
			if(a2[2]=='B'||a2[2]=='A'){
				cout<<1;
				f=1;
			}
			else{
				cout<<0;
			}
		}
		else if(a4[2]=='D'){
			if(a2[2]=='F'){
				cout<<1;
				f=1;
			}
			else{
				cout<<0;
			}
		}
		else{
			if(a2[2]+1==a4[2]||a2[2]-1==a4[2]||a2[2]+2==a4[2]||a2[2]-2==a4[2]&&f1==1){
				cout<<1;
				f=1;
			}
			else{
				cout<<0;
			}
		}
	}
	else{
		cout<<0;
	}
	if(f==1){
		if(a2[2]=='C'||a2[2]=='D'||a4[2]=='C'||a4[2]=='D'){
			if(a2[2]=='C'){
				if(a4[2]=='B'){
				cout<<1;
				
				}
				else{
					cout<<0;
				}
			}
		}
		else if(a2[2]=='D'){
			if(a4[2]=='F'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		
		else if(a4[2]=='C'){
			if(a2[2]=='B'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else if(a4[2]=='D'){
			if(a2[2]=='F'){
				cout<<1;
			}
			else{
					cout<<0;
			}
			
		}
		else{
			if(a2[2]+1==a4[2]||a2[2]-1==a4[2]){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	}
	else{
		cout<<0;
	}
	return 0;
} 
