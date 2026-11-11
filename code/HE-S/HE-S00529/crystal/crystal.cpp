#include<bits/stdc++.h>
using namespace std;
int mian(){
	fropen("crystal.in","r","stdin");
	fropen("crystal.out","w","stdout");
	int n,m,a,c=0;
	int b[10000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		b[i-1]=a;
	}
	while(m=0){
		if(b[0]==b[1]){
	        c=2;
	        if(b[1]==b[2]){
	    	    c=3;
	    	    if(b[2]==b[3]){
	                c=4;
	                if(b[3]==b[4]){
	                    c=5;  
		            }
		            else{
		    	        if(m>=4){
		    	            b[0]=b[0]+1;
			                b[1]=b[1]+1;
			                b[2]=b[2]+1;
			                b[3]=b[3]+1;
		                    m=m-4;
		                }
		            }
		        }
		        else{
		    	    if(m>=3){
		    	        b[0]=b[0]+1;
			            b[1]=b[1]+1;
			            b[2]=b[2]+1;
		                m=m-3;
		            }
		        }
		    }
		    else{
		    	if(m>=2){
		    	    b[0]=b[0]+1;
			        b[1]=b[1]+1;
		            m=m-2;
		        }
		    }  
	    }
	else{
		if(m>=1){
			b[0]=b[0]+1;
		    m=m-1;
		}
	}
	}
	cout<<c<<endl;
	return 0;
}
