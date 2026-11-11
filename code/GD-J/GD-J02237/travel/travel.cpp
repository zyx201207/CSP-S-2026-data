#include<bits/stdc++.h>
using namespace std;
string x1,x2,y1,y2;
int main(){
	cin>>x1>>x2>>y1>>y2;
	if(x1==y1)
	{
		cout<<"1";
		if(x2[0]==y2[0])
		{
			if(x2[1]==y2[1]){
				cout<<1;
				if((x2[2]<=67&&y2[2]<=67)||(x2[2]>67&&y2[2]>67)){
		          cout<<1;
		          if(x2[2]+2==y2[2]+1){
	             	cout<<1;
	                }else{
	                  cout<<0;
      	            }
            	}else{
	        	  cout<<"00";
		        }
			}else{
				cout<<"000";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
