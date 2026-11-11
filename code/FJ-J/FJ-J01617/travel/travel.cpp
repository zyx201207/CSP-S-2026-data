#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;bool s=1;bool cnt=0; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		
	for(int i=0;i<b.size()-1;i++){
		if(b[i]==d[i]){
			
		}else{
			s=0;
		}
	}
	if(s==0){
		cout<<0;
		cout<<0;
		cout<<0;
	}else{
		cout<<1;
		
		if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
			cout<<1;
			if(d[2]+1==b[2]||d[2]-1==b[2]){
				cout<<1;
				cnt=1;
			}
		}
		else if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
			cout<<1;
			if(d[2]+1==b[2]||d[2]-1==b[2]){
				cout<<1;
				cnt=1;
			}
		}
		else{
			cout<<0;
		}
		if(cnt==0){
			cout<<0;
		}
	}
	
	
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	
	return 0;
}  
