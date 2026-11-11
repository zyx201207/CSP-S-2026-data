#include<bits/stdc++.h>
using namespace std;
int main {
freopen{"ang.in",'r',stdin};                                                                                                                                                                          
freopen{"ang.out",'w',stdout};                                                                                                                                                                        
    long long  n,m,r[200000000000000000000000000005];
    cin>>n>>m;
    int sum=0,wse=0
    for(int i=1;i<=n;i++){
		cin>>r[i];
    }for(int i=1;i<=n;i++){
		wse=r[i]&r[i+1];
		if(wse>sum){
		    sum=wse;
	    }else{
	         sum=sum;
	}
    }
    if(n=1){
        cout<<r[1];
    }
    

    
    return 0;
}
