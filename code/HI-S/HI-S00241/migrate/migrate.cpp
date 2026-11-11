#include<bits/stdc++.h>
using namespace std;
long long gm,n,t,a[5100][5100],d,num[5100];
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>gm>>t;
for(int ii=1;ii<=t;ii++){	
cin>>n>>d;
if(d==1){
for(int i=1;i<=n;i++){
cin>>a[ii][i];
}
cout<<0;
continue;
}
for(int i=1;i<=n;i++){
cin>>a[ii][i];
}
		if(d==2){
			for(int i=1;i<=n-3;i++){
    		    if(a[ii][i+3]-a[ii][i+2]==1&&(a[ii][i+2]-a[ii][i+1]==1&&a[ii][i+1]-a[ii][i]==1)){
    		    	num[ii]++;
				}
				else{
					break;
				}
		    }
		}
		if(d>2){
			if(n<4){
				continue;
				
			}
		    for(int i=1;i<=n-3;i++){
		    	if(a[ii][i+1]-a[ii][i]>d){
		    		break;
				}
    		    if(a[ii][i+d]-a[ii][i]>d){
    		    	if(a[ii][i+3]-a[ii][i+2]+a[ii][i+2]-a[ii][i+1]<=d&&a[ii][i+2]-a[ii][i+1]+a[ii][i+1]-a[ii][i]<=d){
    		    	    num[ii]++;
				    }
				}
			}	
		}
	}
	for(int i=1;i<=t;i++)cout<<num[i]<<'\n';
	return 0;
}
