#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=n;
	while(m--){
		int ans=0;
		for(int i=1;i<=n;i++){
		    for(int j=n-i+1;j<=n;j++){
		    	int cnt=0;
			    while(sum--){
			    	b[j]=a[j];
			    	cnt++;
			    	for(int k=n-i+1;k<=j;k++){
			    		if(b[k]==b[j]){
			    			b[n-i+1]=b[k];
			    			for(int f=n-i+2;f<=j;f++){
			    				b[f]=0;
			    				cnt--;
							}
							break;
						}
					}
				}
				for(int k=n-i+1;k<=n-i+1+cnt;k++){
					if(b[k]==i){
						ans++;
					}
				}
		    }
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
