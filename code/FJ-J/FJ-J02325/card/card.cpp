#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
     	int c[500005]={};
	    for(int j=i;j<=n;j++){
	    	int x=j;
		    for(int k=1;k<=n;k++){
		        if(c[k]==a[j]){
		        	x=k;
		        	for(int r=k;r<=j;r++){
		        		c[r]=0;
					}
				}	
	        }
			c[x]=a[j];
	    }
	    for(int j=1;j<=n;j++){
	    	for(int k=1;k<=n;k++){
	    		if(c[j]==k){
	    			b[k]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
