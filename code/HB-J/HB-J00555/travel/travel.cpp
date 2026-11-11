#include <bits/stdc++.h>
using namespace std;
string rc,xc,rw,xw;
int a[100],b[100];
char c[126],d[126];
int cnt=0,sum=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rw>>xc>>xw;
    if(rc!=xc){
		cout<<"0000";
		return 0;
	} else {
		cout<<"1";
		for(int i=0;i<rw.size();i++){
		if(rw[i]>='1'&&rw[i]<='9'){
			a[cnt]=rw[i];
			b[cnt]=xw[i];
			cnt++;
		    } else {
			   c[sum]=rw[i];
			   d[sum]=xw[i];
			   sum++;
		    }
	    } 
		
	    int f=0;
	    for(int i=0;i<cnt;i++){
		    if(a[i]!=b[i])f=1;
	    }
	    if(f==1)cout<<"000";
	    else {
			cout<<"1";
			int k=0;
			for(int i=0;i<sum;i++){
				if((c[i]>='A'&&c[i]<='C'&&d[i]>='D'&&d[i]<='E')||(d[i]>='A'&&d[i]<='C'&&c[i]>='D'&&c[i]<='E'))k=1;
			}
			if(k==1) cout<<"00";
			else {
				cout<<"1";
				int y=0;
				if(c[1]=='A'&&d[1]=='C'||c[1]=='C'&&d[1]=='A')y=1;
				
				if(y==0)cout<<1;
				else cout<<0;
			}
			
		}
	}
	
	
    return 0;
}
