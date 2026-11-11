#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.im","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,c,d,e,f;
	int C,D,E,F;
	cin>>a>>b>>c>>d>>e>>f;
	C = c%d;
	D = c%e;
	E = d%e;
	F = d%f;
	if(C>D){
	    if(C>E){
	    	if(C>F){
	    		cout<<C<<endl;
			}
		}
	}
    if(D>C){
	    if(D>E){
	    	if(D>F){
	    		cout<<D<<endl;
			}
		}
	}
	if(E>C){
	    if(E>D){
	    	if(E>F){
	    		cout<<E<<endl;
			}
		}
	}
	  if(F>C){
	    if(F>E){
	    	if(F>D){
	    		cout<<F<<endl;
			}
		}
	}
	
	
	
	
	
	
	retirn 0;
}
