#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	int n[4];
	cin>>a>>c>>b>>d;
	if(a==b){
		n[0]=1;
		if(c[0]==d[0]){
		    if(c[1]==d[1]){
			    n[1]=1;
		    	if(c[2]=='A'||c[2]=='B'||c[2]=='C'){
		            if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
			            n[2]=1;
			            if(c[2]=='A'||d[2]=='A'){
			            	if(c[2]=='B'||d[2]=='B'){
			            		n[3]=1;
							}
						}
						if(c[2]=='B'||c[2]=='C'){
							if(d[2]=='C'||d[2]=='B'){
								n[3]=1;
							}
						}
		            }
		            else{
			            n[2]=0;
			            n[3]=0;
		            }
	            }
	            else{
	            	if(d[2]=='D'||d[2]=='F'){
	            		n[2]=1;
	            		n[3]=1;
					}
					else{
						n[2]==0;
						n[3]==0;
					}
				}
		    }
	    }
	    else{
		n[1]=0;
	    }
	}
	else{
		n[0]=0;
	}
	 cout<<n[0]<<n[1]<<n[2]<<n[3]<<endl;
	return 0;
}
