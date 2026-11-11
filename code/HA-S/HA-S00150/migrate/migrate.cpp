#include <bits/stdc++.h>
using namespace std;
long long t,n,d;
int c;
struct ed{
	long long ge=0,ans=0x3f3f;
}a2[200200];

long long a[2000200];


long long b[2000200];

int main(){
	freopen("migrate1.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	memset (a,0,sizeof(a));

	cin >> c >> t ;
	if (c>25){
		return 0;
	}
	for (int i=1;i<=t;i++){
		int y=0;
		cin >> n >> d;
    	for (int j=1;j<=n;j++){
	      cin >> a[j];}
	    for (int j=1;j<=n;j++){
	         a2[j].ans=0;
            a2[j].ge=1;
		for(int k=2;k<=n;k++){
	        for(int p=k-1;p>=1;p--) {
	        
		        int co= a[k]-a[p];
		            if(co <=d ){
		            	if(a2[k].ans-1>a2[p].ans){
		                a2[k].ans =	a2[p].ans+1;
		                a2[k].ge=a2[p].ge;
		                 } 
						if(a2[k].ans=a2[p].ans-1){
		                 a2[k].ge+=a2[p].ge;
		                 }}
		     	
		     			}}
		     			
		     		
		     	
		   
			for(int m=j;m<=n;m++){//shi
			
		    if(a2[m].ge==2){
		        y++;
				} 
				}}cout<< y<<endl;}
		     
	         
	

	return 0;
}
