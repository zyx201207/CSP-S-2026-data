#include<bits/stdc++.h>
using namespace std;
long long a,b,c1[300005],c[300005],c2[300005],c3[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
	    cin>>c[i];  
	}
	for(int i=2;i<=a+1;i++){
	    for(int o=i-1;o<=a;o++){
	    	c2[c[o]]++;
	    	c1[o]=c[o];
	    	if(c2[c[o]]==2){
	    		int p=o-1;
	    		while(c1[p]!=c1[o]){
	    			c2[c1[p]]=0;
					c1[p]=0;
	    			p--;
				}
				c2[c1[p]]--;
				c1[p]=0;
			}		
		}
		for(int o=1;o<=b;o++){
			if(c2[o]>0 && c2[o]<=b){
				c3[o]+=c2[o];
			}	
			c2[o]=0;
			c1[o]=0;
		}	
	}
	for(int o=1;o<=b;o++){
		cout<<c3[o]<<" ";	
	}
	return 0;
} 
