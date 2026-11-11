#include<bits/stdc++.h>
using namespace std;
long long b[100005],d[100005];
int main(){
    freopen("travel.in","r","stdin")
    freopen("travel.out","w","stdout")
	long long a,c;
	cin>>a>>c; 
	if(a=c){
		cout<<1;
		if(b[0]=d[0]){
            if(b[1]=d[1]){
		        cout<<1;
		        if(b[2]="D" or b[2]="F" and d[2]="D" or d[2]="F"){
	                cout<<11;
	            }if(b[2]="A" or b[2]="B" or b[2]="C" and d[2]="A" or d[2]="C" or d[2]="B"){
	                cout<<1;
	                if(b[2]="A" or b[2]="C" and d[2]="A" or d[2]="C"){
	                    cout<<0;
					}else{
					    cout<<1;
					}
	            }else{
	                cout<<00;
	            }
	        }else{
	            cout<<000;
		    }
        }else{
            cout<<000;
	    }
    }else{
    	cout<<0000;
    }
    return 0;
}
