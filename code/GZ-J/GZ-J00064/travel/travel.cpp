//  GZ-J00064  兰椿楸  毕节七星关东辰实验学校
#include<iostream>
using namespace std;
int  main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;;
	cin>>c1>>s1>>c2>>s2;
	string sa,sb;
	if(c1==c2){
		cout<<"1";
		}
		else {
		    cout<<"0000";
			return 0;	
		}
		
	
	for(int i=0;i<=1;i++){
		char a;
		a=s1[i];
		sa=sa+a;
	}
	for(int i=0;i<=1;i++){
	    char b;
    	b=s2[i];
		sb=sb+b;
	}
	if(sa==sb){
		cout<<"1";
		}
		else {
		    cout<<"000";
			return 0;	
		}
	char n,m;
	n=s1[2];m=s2[2];
	for(char i='A';i<='F';i++){
		if(n==i&&i<='C'){
			if(m=='A'||m=='B'||m=='C'){
				cout<<"1";
		    }
			if(m=='D'||m=='F'){
				cout<<"00";
		    }	
			return 0;	    
		}
		if(n==i&&i>'C'){
			if(m=='F'||m=='D'){
				cout<<"1";
			}
			if(m=='A'||m=='B'||m=='C'){
				cout<<"0";
		    }	
			return 0;		
		}
	}
	for(char i='A';i<='F';i++){
		if(n==i&&i<='C'){
			if(m==i-1||m==i+1){
				cout<<"1";
		    }
			if(m!=i-1&&m!=i+1){
				cout<<"0";
		    }		    
		}
		if(n==i&&i>'C'){
			if(m=='F'||m=='D'){
				cout<<"1";
			}			
		}
	}
				
	fclose(stdin);
	fclose(stdout);
	return 0;
}
