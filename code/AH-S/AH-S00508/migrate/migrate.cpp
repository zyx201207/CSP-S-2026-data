#include <bits/stdc++.h>

using namespace std;

const int N = 300 + 10;
long long c,t;
long long n,m;
long long a[N] = {0};
long long b[N] = {0};
long long dp[N][N] = {0};
long long daan = 0;
bool p = 0;

long long MIN(long long x,long long y){
	if(x < y){
		return x;
	}
	return y;
}

int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	
	while(t--){
		int l = 1,r = 1;
		int daan = 0;
		
		cin>>n>>m;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		
		while(r < n){
			r++;
			
			while(1){
				if(a[r] - a[l] > m){
					l++;
				}else{
					b[r] = l;
					
					break;
				}
			}
		}
		
		for(int sss = 1;sss <= n;sss++){
			memset(dp,0,sizeof(dp));
			dp[sss][0] = 1;
			
	    	for(int i = sss + 1;i <= n;i++){
	    		for(int j = b[i];j < i;j++){
	    			for(int k = 0;k <= n - 1;k++){
		    			dp[i][k + 1] = MIN((dp[i][k + 1] + dp[j][k]),5);
	    			}
	    		}
	    	}
	    	for(int i = 1;i <= n;i++){
		    	p = 0;//1 1 
		    	
	    		for(int j = 1;j <= n;j++){
		    		if(dp[i][j] > 0){
		    			p = 1;
		    		}else{
		    			continue;
					}
		    		if(dp[i][j] == 2){
		    			daan++;
					}
			    	if(p){
			    		break;
			    	}
			    }
	    	}
		
	    }
	    
	    cout<<daan<<endl;
	}
	
	return 0;
}
