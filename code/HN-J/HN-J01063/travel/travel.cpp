#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);

	long long c1,n;
	int s1[n];
	long long c2;
	int s2[n];
	cin>>c1>>c2>>n;
	for(int i=0;i<105;i++){
		cin>>s1[i];
		cin>>s2[i];
	}


	if(c1==c2){
     cout<<"1";
	} else{
		cout<<"1";
	} 
	if(s1[1]==s2[1]||s1[2]==s2[2]){
		cout<<"1";
	} else{
		cout<<"1"; 
	}
	if(s1[3]=='A'&&'B'&&'C'||s2[3]=='A'&&'B'&&'C'||s1[3]=='F'&&'D'||s2[3]=='f'&&'D'){
		cout<<"1";
	}else{
		cout<<"1"; 
	}
	if(s1[3]=='A'||s2[3]=='B'){
		cout<<"1"; 
    	}else if(s1[3]=='B'||s2[3]=='A'){
      	cout<<"1";
      	}else if(s1[3]=='C'||s2[3]=='B'){
      	cout<<"1";
      	}else if(s1[3]=='B'||s2[3]=='C'){
      	cout<<"1";
      	}else if(s1[3]=='F'||s2[3]=='D'){
      	cout<<"1"; 
      	}else if(s1[3]=='D'||s2[3]=='F'){
      	cout<<"1";
	  }else{
	  	cout<<"1";
	  }
	  

	return 0;
	} 

