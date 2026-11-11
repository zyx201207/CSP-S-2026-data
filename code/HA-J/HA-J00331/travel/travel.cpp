#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char c[10],d[10];
	cin>>a>>c>>b>>d;
	if(a!=b){				
		cout<<"0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	};
	cout<<1;
	if(c[0]==d[0]&&c[1]==d[1]){
		cout<<1; 
		if(c[2]=='A'){
			if(d[2]=='B')cout<<"11";
			if(d[2]=='C')cout<<"10";
			if(d[2]=='D')cout<<"00"; 
			if(d[2]=='E')cout<<"00";	
		}        
		if(c[2]=='B'){         
			if(d[2]=='A')cout<<"11";
			if(d[2]=='C')cout<<"11";
			if(d[2]=='D')cout<<"00";
			if(d[2]=='E')cout<<"00";
		}        
		if(c[2]=='C'){        
			if(d[2]=='B')cout<<"11";
			if(d[2]=='A')cout<<"10";
			if(d[2]=='E')cout<<"00";
			if(d[2]=='F')cout<<"00";
		}          
		if(c[2]=='D'){         
			if(d[2]=='B')cout<<"00";
			if(d[2]=='C')cout<<"00";
			if(d[2]=='A')cout<<"00";
			if(d[2]=='E')cout<<"11";
		}        
		if(c[2]=='E'){         
			if(d[2]=='B')cout<<"00";
			if(d[2]=='C')cout<<"00";
			if(d[2]=='D')cout<<"11";
			if(d[2]=='A')cout<<"00";
		}        
	}                    
	else{                
		cout<<"000";          
	};                   
	fclose(stdin);
	fclose(stdout);
	return 0;
	}

