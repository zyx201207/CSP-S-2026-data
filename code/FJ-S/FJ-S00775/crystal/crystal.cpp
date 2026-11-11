#include<bits/stdc++.h>
using namespace std;
int n;
long long u;
long long sum=0,all=0;
long long a[5005]={0},b[5005]={0};
unsigned long long m,c=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	sum=a[2]-a[1];
	bool p=1;
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1])!=sum){
			p=0;
			break;
		}
	}
	if(p){
		u=m/sum;
		for(int i=1;i<=n;i++){
			if(((i*(i-1))/2)>u){
				cout<<i-1;
				return 0;
			}
			if(i==n){
				cout<<n;
				return 0;
			}
		} 
	}
	bool flag=0;
	if(a[1]<0)
	    flag=1;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			if(flag){
				if(a[i]<=0){
					c-=a[i];
					if((c-((0-a[i])*i))>m){
			 	  	    b[j]=i-1;
			  	 	    break;
			  	  }
				}
		   	 	else{
		    		c+=(a[i]-a[1]);
		    		if(((a[i]-a[1])*i-c)>m){
			   	   		b[j]=i-1;
			   	    	break;
			    	}
				}
			}else{
				c+=a[i];
		    	if(((a[i]*i)-c)>m){
			  		b[j]=i-1;
			    	break;
			    }
			}
			if(i==n)
				b[j]=i-1;
		}
	}
	for(int i=1;i<=n;i++){
		all=max(all,b[i]);
	}
	cout<<all;
	return 0;
}
