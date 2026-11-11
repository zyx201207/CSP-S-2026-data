#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
		    cout<<"1";
	    }
	    else{
		    cout<<"0";
	    }
	}
	else{
		cout<<"0";
	}
	char a1=s1[2],a2=s2[2];
	if(c1==c2){
	    if(s1[0]==s2[0]&&s1[1]==s2[1]){
		    if(a1=='A'&&a2=='B'){
			    cout<<"1";
		    }
		    else if(a1=='B'&&a2=='A'){
			    cout<<"1";
		    }
		    else if(a1=='A'&&a2=='C'){
			    cout<<"1";
		    }  
		    else if(a1=='C'&&a2=='A'){
			    cout<<"1";
		    }
		    else if(a1=='B'&&a2=='c'){
			    cout<<"1";
		    }
		    else if(a1=='C'&&a2=='B'){
			    cout<<"1";
		    }
		    else if(a1=='E'&&a2=='F'){
			    cout<<"1";
		    }
		    else if(a1=='F'&&a2=='E'){
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
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
		    if(a1=='A'&&a2=='B'){
		        cout<<"1";
	        }
	        else if(a2=='A'&&a1=='B'){
		        cout<<"1";
	        }
	        else if(a2=='C'&&a1=='B'){
		        cout<<"1";
	        }
	        else if(a2=='B'&&a1=='C'){
		        cout<<"1";
	        }
	        else if(a2=='D'&&a1=='F'){
		        cout<<"1";
	        }
	        else if(a2=='F'&&a1=='D'){
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
	return 0;
} 
