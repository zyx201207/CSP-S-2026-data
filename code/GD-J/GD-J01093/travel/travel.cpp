#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rc,xc;
	char r[4],x[4];
	cin>>rc;
	for(int i=0;i<3;i++) cin>>r[i];
	cin>>xc;
	for(int i=0;i<3;i++) cin>>x[i];
	if(rc==xc){
	  cout<<"1";
	  if(r[0]==x[0]&&r[1]==x[1]) {
	        cout<<"1";
	        if((('A'<=r[2]&&r[2]<='C')&&('A'<=x[2]&&x[2]<='C'))||(('D'==r[2]||r[2]=='F')&&('D'==x[2]||x[2]=='F'))) {
			    cout<<"1";
			    int a=r[2],b=x[2];
			    //cout<<a<<b;
			    if((min(a,b)+1==max(a,b))||(min(a,b)=='D'&&max(a,b)=='F')) cout<<"1";
			    else cout<<"0";
		    }
		    else cout<<"00";
	    }
	    else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}  
