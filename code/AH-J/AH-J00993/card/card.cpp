#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],cnt=0,v=0;
    cin>>n>>m;
    int x=n;
    while(x--){
		v++;
    	int b[500005];
    	for(int i=v;i<n;i++){
    		b[i]=a[i];
    		for(int j=0;j<b.size();j++){
    			if(b[i]==b[j]){
    				for(int z=i;z<j;z++){
    					
					}
				}
			}
		}
	}
    return 0;
}
