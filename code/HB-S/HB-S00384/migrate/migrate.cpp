#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[10000005],sum,v1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		sum=0;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		int v;
		for(int j=3;j<=n;j++){
			if((x[j]-x[j-1]==x[j-1]-x[j-2])&&x[j]>=0&&x[j-1]>=0&&x[j-2]>=0){
				v=1;
			}
			else{
				v=0;
				break;
			}
		}
		if(v!=1){
    		for(int j=1;j<=n;j++){
	    		if((x[(n+1)/2]-x[j]<=d)||(x[j]-x[(n+1)/2]<=d)){
	    			v=2;
	    		}
	    		else{
	    			v=0;
	    			break;
	    		}
	    	}
	    }
		if(v==1){
			for(int j=1;j<=n-d;j++){
				for(int k=j+d+1;k<j+2*d;k++){
					if(k<=n){
						sum++;
					}
				}
			}
			cout<<sum;
		}
		else if(v==2){
			cout<<0;
		}
	}
	return 0;
}
