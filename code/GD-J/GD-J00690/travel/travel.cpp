#include<bits/stdc++.h>
using namespace std;
long long x[1000000];
int main(){
	long long a,b,c,i,j,m,n;
	char y,z;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>m>>y>>b>>n>>z;
	
	if(a==b){
		cout<<1;
		if(m==n){
			cout<<1;
			if(y<='C' && z<='C' || y>'C' && z>'C'){
				cout<<1;
				if(abs(y-z)==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00"; 
			}
		} 
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
