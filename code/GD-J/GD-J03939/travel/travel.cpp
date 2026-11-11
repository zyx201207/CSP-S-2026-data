#include <bits/stdc++.h>
using namespace std;
string sa,sb,ca,cb;
stringstream ss; 
char p,q;
int a,b,c,d,ba,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	ss.clear();
	ss<<ca;
	ss>>a;
	
	ss.clear();
	ss<<cb;
	ss>>b;
	
	if(a==b){
		
		cout<<"1";
	    c=sa[0]-'0';
	    c=c*10+sa[1]-'0';
	    
	    d=sb[0]-'0';
	    d=d*10+sb[1]-'0';
	    if(c==d){
	    
	    	cout<<"1";
	    	p=sa[2];
	    	q=sb[2];
	    	if(p=='D'||p=='F') ba=1;
	    	else ba=0;
	    	if(q=='D'||q=='F') bb=1;
	    	else bb=0;
	    	if(ba==bb){
	    	
	    		cout<<"1";
	    		if(p<q) swap(p,q);
	    		int t;
	    		t=p-q;
	    		
	    		if((ba==1&&bb==1)||t<=1){
	    		
	    			cout<<"1";
				}
				else{
				
					cout<<"0";
				} 
			}
			else {
			
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
	fclose(stdin);
	fclose(stdout);
	
} 
