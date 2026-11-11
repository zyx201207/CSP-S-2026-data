#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005],c[500005];
int h(int i,int j){
	int tot1=0,tot2=0;
	for(int k=i;k<=j;k++){
		tot1=a[k]+tot1;
	}
	tot1=tot1/(j-i+1);
	for(int k=i;k<=j;k++){
		tot2=tot2+abs(tot1-a[k]);
	}
	return tot2;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int num=0,sum=0;
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
		if(i==1) num=c[i];
		if(num!=c[i]) sum=1;
	}
	
	if(sum==1){
	    int tol=0;
	    for(long long i=1;i<=n;i++){
    	    for(long long j=i+1;j<=n;j++){
    		    tol=h(i,j);
    	    	if(tol<=m) ans=max(ans,j-i+1);
    	     	tol=0;
        	}
	    }
	    cout<<ans;
	}else{
		int r=0,ans=1;
		for(int i=1;i<=n/2+1;i++){
		    r=r+num*2*i;
			if(r>m){
			    if(r-num*i<=m){
			    	ans++;
			    	break;
				}else{
					break;
				}	
			}else{
			ans=ans+2; 
			}
			if(ans>=n){
				ans=n;
				break;
			} 
		}
		cout<<ans;
	}
	return 0;
}
