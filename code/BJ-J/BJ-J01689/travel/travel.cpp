#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
    string a,n,b,m;
    
    cin>>a>>n>>b>>m;
    
    if(a==b){
        cout<<1;
        if(n[0]==m[0] && n[1]==m[1]){
		    cout<<1;
		    if(n[2]-m[2]==1){
		        cout<<1;
		        cout<<1;
	        }
	        else if(m[2]-n[2]==1){
		        cout<<1;
		        cout<<1;
	        }
	        else if(n[2]-m[2]==2){
		        cout<<1;
		        cout<<0;
	        }
	        else if(m[2]-n[2]==2){
		        cout<<1;
		        cout<<0;
	        }
	        else if(n[2]-m[2]==3){
		        cout<<1;
		        cout<<0;
	        }
	        else if(m[2]-n[2]==3){
		        cout<<1;
		        cout<<0;
	        }
	        else if(n[2]-m[2]==4){
		        cout<<1;
		        cout<<0;
	        }
	        else{
	            cout<<0;
	            cout<<0;
	        }
	        
        }
        else{ 
		    cout<<0;
		    cout<<0;
		    cout<<0;
	    }
    }
    else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
    
	
    return 0;
}