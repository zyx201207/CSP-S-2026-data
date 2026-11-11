#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[500005],ans[300005];
    cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int rcd=n;	
    while(rcd--){
    	int i=n-rcd+1;
    	for(int k=i+1;k<=n;k++){
    	    for(int j=i;j<=k;j++){
    	    	if(a[j]==a[k]){
    	    		for(int t=j;t<k;t++){
    	    			a[t]=0;
					}
					continue;
				}
			}	
		}
		for(int i=n-rcd+1;i<=n;i++){
			ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
