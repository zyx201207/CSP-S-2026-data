#include<bits/stdc++.h>
using namespace std;

int main(){
	// freopen("travel1.in","r",stdin);
	// freopen("travel1.out","w",stdout);
	
	// freopen("travel2.in","r",stdin);
	// freopen("travel2.out","w",stdout);
	
	// freopen("travel3.in","r",stdin);
	// freopen("travel3.out","w",stdout);
	
	// freopen("travel4.in","r",stdin);
	// freopen("travel4.out","w",stdout);
	
	// freopen("travel5.in","r",stdin);
	// freopen("travel5.out","w",stdout);
	
	string a,b,n,m;
	
	cin>>a>>n>>b>>m;
	
	if(a!=b){
		cout<<"0000";
		
		return 0;
	}else{
		cout<<'1';
		
		if(n[0]==m[0] && n[1]==m[1]){
		    cout<<'1';
		    
		    if((n[2]<='C' && m[2]<='C') || (n[2]>='D' && m[2]>='D')){
				cout<<'1';
				
				if(n[2]==m[2]){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
			}
	    }else{
			cout<<"000";
		}	
	}
	
	return 0;
}
