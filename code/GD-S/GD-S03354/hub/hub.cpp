#include<bits/stdc++.h>
using namespace std;
int minn=INT_MAX,c,t,n,k,u[10000005],v[10000005],x[10000005];
int main(){
	freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t<0){
    	cin >> n >> k;
    	for(int i=1;i<=n;i++){
    		cin >> u[i] >> v[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(u[i]<u[j]){
					x[i]=u[j]-u[i];
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(x[i]<minn){
				minn=x[i];
			}
		}
		cout << minn << endl;
		t--; 
	}
    
    fclose(stdin);
    fclose(stdout);
	return 0;
} 
