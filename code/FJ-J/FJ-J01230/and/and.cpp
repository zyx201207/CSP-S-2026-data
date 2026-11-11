#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[10000],iz[10000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
    int sum=0;
    int s[10000];
    for(int i1=0;i1<n;i1++){//meiyiju
    	for(int i2=0;i2<n;i2++) s[i2]=0;//chongzhi
    	for(int i=i1;i<n;i++){
    	    for(int j=0;j<i;j++){//bianlimeiyizhangpai
    		    if(a[i]==s[j]){//shouzou
    			    for(int l=j-1;l<n;l++){
    				    s[l]=0;
			    	}	
			   }
	     	}
		    s[i]=a[i];
	}
	    for(int op=1;op<=m;op++){
	    	for(int po=0;po<n;po++){
	    		if(s[po]==op){
	    			iz[op]++;
	    			
				} 
			}
		}
	}
    for(int i=1;i<=m;i++){
    	cout<<iz[i]<<' ';
	}
	return 0;
}
