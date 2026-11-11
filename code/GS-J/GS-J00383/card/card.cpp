#include<bits/stdc++.h>
using namespace std;\
long long zhuo[1000000005];

int K(long long z[1000000005],long long m){
	for(int i=0;i<1000000005;i++){
		if(z[i]==m){
			return 1;
		}else{
			return 0;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a=0,b=0,n[1000000005];
	cin>>a>>b;
	long long a1[a+1];
	long long tong[b+5];

	for(int i=0;i<a;i++){
		cin>>a1[i];
	}	
	
	for(int i=1;i<=a;i++){
	    for(int j=i-1;j<a;j++){
	    	if(K(zhuo,a1[j])){
	    		for(int p=0;p<1000000005;p++){
	    		if(zhuo[p]==a1[j]){
	    			zhuo[p]=0;
	    			for(int y=p;y<1000000005;y++){
	    				zhuo[y]=0;
					}
				}
			}
	    }else{
		  for(int o=0;o<a;o++){
		  	if(zhuo[o]==0){
		  		zhuo[o]=a1[j];
		  		break;
			  }
		  }
	   }
	   
		}
		for(int o=0;o<a;o++){
			n[zhuo[o]]+=1;
		}
	}
    for(int i=0;i<a;i++){
    	cout<<n[i];
	}
	return 0;
}
