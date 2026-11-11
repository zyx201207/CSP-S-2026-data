#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,n1,m,m1;
	cin>>n>>n1>>m>>m1;
	
	if(n!=m){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		int a=0,a1=1,b=0,b1=1;
		for(int i=0;i<3;i++){
			if(!(n1[i]>='A'&&n1[i]<='Z')){
				a=(n1[i]-'0')*a1;
			}
			a1*=10;
		}
	    for(int i=0;i<3;i++){
			if(!(m1[i]>='A'&&m1[i]<='Z')){
				b=(m1[i]-'0')*b1;
			}
			b1*=10;
		}
		
		if(a!=b){
			cout<<"000";
			 return 0;
		}else{
			cout<<1;
			
			char x,y;
			for(int i=0;i<n1.size();i++){
				if(n1[i]>='A'&&n1[i]<='Z'){
					x=n1[i];
					break;
				}
			}	
			for(int i=0;i<m1.size();i++){
				if(m1[i]>='A'&&m1[i]<='Z'){
					y=m1[i];
					break;
				}
			}
				
			if(((x>='A'&&x<='C')&&(y>='A'&&y<='C'))||
			   ((x>='D'&&x<='F')&&(y>='D'&&y<='F'))){
				cout<<1;
				if(x+1==y||y+1==x){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
				return 0;
			}
			
		}
	}
	
	return 0;
} 
