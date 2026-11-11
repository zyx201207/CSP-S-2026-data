#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long x[1000001],d,k,a,b;
void ss(int l,int r,long long mid){
    if(l==r){
    	if(mid<a){
			if(b==2){
    	        k++;	
			}
			if(b==3){
    	        k--;	
			}
    		a=mid;
    		b=1;
		}else if(mid==a){
			b++;			
		}
    	return ;
	}
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[l]<=d){
			ss(i,r,mid+1);
		}else{
			break;
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;i++){
    	scanf("%d%d",&n,&d);
    	k=0;
    	for(int j=1;j<=n;j++){
    		scanf("%d",&x[i]);
		}
		for(int j1=1;j1<n-1;j1++){
    	    for(int j2=j1+2;j2<=n;j2++){
				a=100000000000,b=0;
    	        ss(j1,j2,0);
			}
		}
		printf("%lld\n",k);
	}
	return 0;
} 
