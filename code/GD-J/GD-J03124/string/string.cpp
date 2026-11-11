#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,a1,c=0;
    string b,b1;
    cin>>n;
    cin>>a>>b; 
	for(int i=1;i<n;i++){
        cin>>a1>>b1;
		if(b1!=b){
			c=1;
		}
	}
	if(c==0){
	
 		cout<<0;
	}
	else{
		cout<<2;
	}


}
