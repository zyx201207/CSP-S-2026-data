#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[1000005],b[1000005],cnt=0,x,s=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		cnt=0;
		for(int j=1;j<=n;j++){
			cin>>a[j];
				
	    }
	    x=a[1];
	    for(int k=1;k<=n;k++){
	 
	    	if(a[k+1]-a[k]<=d){
	    		if(a[k+2]-a[k]<=d){	
	    			x=a[k+2];
	    			cnt++;
	    			if(a[k]+d>=a[k+3]){
	    				
	    				break;
					}

				}
				else{
					x=a[k+1];
				}
			}
			if(x>=a[n]){
				
	    		break;
			}
			
			
			b[i]=cnt;
			

		

		}

	    

	}
	for(int i=1;i<=t;i++){
		cout<<b[i];
	}

	return 0;
}
