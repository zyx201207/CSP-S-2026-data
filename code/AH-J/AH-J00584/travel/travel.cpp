#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("traval.in","r",stdin);
    freopen("traval.out","w",stdout);
    char a[4],b[4],c[3],d[3];
    cin>>c>>a;
    cin>>b>>d;
    if(c[0]==d[0]&&c[1]==d[1]){
		cout<<1;
		if(a[1]-'0'==b[1]-'0'&&a[0]==b[0]){
			cout<<1;
		    if(a[2]>='D'&&b[2]>='D'||a[2]<'D'&&b[2]<'D'){
				cout<<1;
		        if(a[2]-b[2]==1||a[2]-b[2]==-1){
				    cout<<1;		    
				    }
				else{ cout<<0; }
				     
				 }
		    else {cout<<0<<0;}
		       
		}
		else{cout<<0<<0<<0;}
		    
		}
	else
	    cout<<0<<0<<0<<0;
    return 0;
}

