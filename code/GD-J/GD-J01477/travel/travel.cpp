#include <bits/stdc++.h>
using namespace std;
    int pa(char n){
	if(n='A') return 1;
	if(n='B') return 2;
	if(n='C') return 3;        
	if(n='D') return 4;
    if(n='F') return 5;
}
int main(){
	freopen("travel.in","r",stdin);
	
	freopen("travel.out","w",stdout);
	int A;
	cout<<pa(A); 
	char a[5];
	char b[5];
	char c[5];
	char d[5];
	cin>>a>>b>>c>>d;
    if(a[0]==c[0]&&a[1]==c[1]) {
    	cout<<1;
    	if(b[2]==d[2]) {
    		cout<<1;
    		if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')) {
    			cout<<1;
    			if(pa(b[2])>pa(d[2])){
    	            if(pa(b[2])-pa(d[2])==1) cout<<1;
    	            else cout<<0;
	            }
	            else{
		            if(pa(d[2])-pa(b[2])==1) cout<<1;
    	            else cout<<0;
	            }
			}
			else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')){
				cout<<1;
    			if(pa(d[2])>pa(b[2])){
    	            if(pa(d[2])-pa(b[2])==1) cout<<1;
    	            else cout<<0;
	            }
	            else{
		            if(pa(b[2])-pa(d[2])==1) cout<<1;
    	            else cout<<0;
	            }
			}
            else cout<<0<<0;
		}
	    else cout<<0<<0<<0; 
	}
    else cout<<0<<0<<0<<0;   
	return 0;
}
