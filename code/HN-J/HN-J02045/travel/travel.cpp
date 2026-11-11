#include<bits/stdc++.h>
using namespace std;
string c,s,c2,s2;
int z=0,y=0,x[3]={0,1,2},r,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c2>>s2;
		if(c[1]==c2[1]){
		cout<<1;
		if(s[1]==s2[1]){
			cout<<1;
			for(int i=0;i<=2;i++){
				r=s[2];
				t=s2[2];
				if(r==x[i]){
					z=1;
				}
				if(t==x[i]){
					y=1;
				}
			}
			if(z==y){
				cout<<1;
				if(s[2]-s2[2]==1||s[2]-s2[2]==-1){
					cout<<1;
				}
				else{
					cout<<"0";
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
} 
