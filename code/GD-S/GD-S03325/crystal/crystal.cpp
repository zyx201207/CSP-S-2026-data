#include <bits/stdc++.h>
using namespace std;
int a[100010];
int a1[100010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ma=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==a[1]){
        	ma=i;
		}
    }
    for(int i=2;i<=n;i++){
    	int m1=m;
    	for(int j=i-1;j>=1;j--){
    		if(a[j]==a[i]){
    			m1++;
			}
		}
    	int maxi=1;
    	int q=a[i-maxi];
		while(m1--){
			if(maxi==i){
				break;
			}
    		q++;
    		if(q==a[i]){
    			maxi++;
    			q=a[i-maxi];
    			if(ma<maxi){
    				for(int c=i+1;c<=n;c++){
    					if(a[c]==a[i]){
    						maxi++;
						}else{
							break;
						}
					}
    				ma=maxi;
				}
			}
		}
    }
	cout<<ma;
    return 0;
}
