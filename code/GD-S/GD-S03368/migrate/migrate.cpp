#include<bits/stdc++.h>
using namespace std;
int n,c,t,d,s,x[1000000],b[100000][100000];
int p(int m,int k){
	if(x[k]-x[m]<=d){
		return 0;
	}
	else{
		int g=1,r=0;
		for(int i=m+1;i<k;i++){
			if(x[i]-x[m]>g*d){
				g++;
			}
		}
	  	for(int i=1;i<=g;i++){
			if(r>2){
				return 0;
			}
			for(int i=m+1;i<=k;i++){
				int y=1;
			     
	    	}
		}
		if(r==2){
			return 1;
		}
		else{
			return 0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
    	cin>>n>>d;
    	for(int j=1;j<=n;j++){
    	    cin>>x[j];  	
     	}
     	for(int j=1;j<n;j++){
    	    for(int l=j+1;l<=n;l++){
    	    	s=s+p(j,l);
	        }	
	    }
	    cout<<"0";
	}	
}
