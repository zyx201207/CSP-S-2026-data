#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,t,n,d,a[100],f1[100][100],x[100];
	cin>>c>>t;
	for(int p=1;p<=t;p++){
	    x[p]=0;
		cin>>n>>d;
	    for(int i=1;i<=n;i++){
		    cin>>a[i];
		}
	    for(int i=1;i<=n;i++){
		    if((a[i+1]-a[i])>d){
			    f1[i][i+1]=1;
		    }
	    }
	    for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    bool w=true;
			    for(int q=i;q<=j;q++){
		            if(f1[q][q+1]==1){
			            w=false;
		            }
	            }
	            if(w==true){
	        	    if((a[j]-a[i])%2==1&&(a[j]-a[i])/2==1){
	        		    x[p]++;
				    }
			    }
		    }
	    }
	}
	for(int i=1;i<=t;i++){
		if(i!=t){
			cout<<x[i]<<endl;
		}else{
			cout<<x[i];
		}
	}
	return 0;
}
