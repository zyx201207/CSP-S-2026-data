#include<bits/stdc++.h>
using namespace std;
int r_,x_;
char x_r[5],x_x[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r_;
	for(int i=1; i<=3; i++) {
		cin>>x_r[i];
	}
	cin>>x_;
	for(int i=1; i<=3; i++) {
		cin>>x_x[i];
	}
	if(r_==x_) {
		cout<<1<<" ";
	    }else{
		    cout<<0<<" "<<0<<" "<<0<<" "<<0;
		    return 0;
	    }

		    if(x_r[1]==x_x[1]&&x_r[2]==x_x[2])
	    {
		 	cout<<1<<" ";
	    }else{
		    cout<<0<<" "<<0<<" "<<0;
		    return 0;
	    }
	    if(((x_r[3]=='A'||x_r[3]=='B'||x_r[3]=='C')&&(x_x[3]=='A'||x_x[3]=='B'||x_x[3]=='C'))||((x_r[3]=='E'||x_r[3]=='F')&&(x_r[3]=='E'||x_r[3]=='F')))
	     {
	     
		 	cout<<1<<" ";
	    }else{
	    
		    cout<<0<<" "<<0;
		    return 0;
	    }
	    if((x_r[3]=='B'||x_x[3]=='B')||(x_r[3]=='E'||x_r[3]=='E'))
	    {
	    	cout<<1<<" ";
		}else{
			cout<<0<<" ";
		}
		
		    return 0;
	    }
