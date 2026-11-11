#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
    	cout<<1;
		
	if(b[1]==d[1]){
		cout<<1;
		if(a[3]<='C'&&b[3]<='C'||a[3]>='D'&&b[3]>='D'){
		cout<<1;if(int(a[3])+1==b[3]||int(a[3])-1==b[3]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	}
	else{
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
	
	
	
	return 0;
}
