#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
long long a[MAXN];
int n, m;
bool b[MAXN];

int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i];
	}
    
    long long maxn = 0;
    
    if(m == 1) {
    	for(int i = 1; i <= n; i ++) {
    		maxn = max(maxn, a[i]);
		}
		cout << maxn;
		return 0;
	}
    
    if(m == 2&&m!=n) {
    	for(int i = 1; i <= n; i ++) {
    		for(int j = i+1; j <= n; j ++) {
    			long long x = a[i] & a[j];
    			if(x > maxn) maxn = x;
			}
		}
		cout << maxn;
		return 0;
	}
	
	if(m == 3&&m!=n) {
    	for(int i = 1; i <= n; i ++) {
    		for(int j = i+1; j <= n; j ++) {
    			for(int k = j+1; k <= n; k ++) {
    			    long long x = a[i] & a[j] & a[k];
    			    if(x > maxn) maxn = x;	
				}

			}
		}
		cout << maxn;
		return 0;
	}
	
	if(m == 4&&m!=n) {
    	for(int i = 1; i <= n; i ++) {
    		for(int j = i+1; j <= n; j ++) {
    			for(int k = j+1; k <= n; k ++) {
    				for(int l = k+1; l <= n; l ++) {
    			    	long long x = a[i] & a[j] & a[k] & a[l];
    			    	if(x > maxn) maxn = x;	    					
					}
				}
			}
		}
		cout << maxn;
		return 0;
	}
	
	if(m == 5&&m!=n) {
    	for(int i = 1; i <= n; i ++) {
    		for(int j = i+1; j <= n; j ++) {
    			for(int k = j+1; k <= n; k ++) {
    				for(int l = k+1; l <= n; l ++) {
    					for(int o = l+1; o <= n; o ++) {
     			    		long long x = a[i] & a[j] & a[k] & a[l];
    			    		if(x > maxn) maxn = x;	     						
						}
					}
				}
			}
		}
		cout << maxn;
		return 0;
	}
	
	if(m == 6&&m!=n) {
    	for(int i = 1; i <= n; i ++) {
    		for(int j = i+1; j <= n; j ++) {
    			for(int k = j+1; k <= n; k ++) {
    				for(int l = k+1; l <= n; l ++) {
    					for(int o = l+1; o <= n; o ++) {
    						for(int i1 = o+1; i1 <= n; i1 ++){
    							
							
     			long long x = a[i] & a[j] & a[k] & a[l] & a[i1];
    			    		if(x > maxn) maxn = x;	     						
						}}
					}
				}
			}
		}
		cout << maxn;
		return 0;
	}

if(m == 7&&m!=n) {
    	for(int i = 1; i <= n; i ++) {
    		for(int j = i+1; j <= n; j ++) {
    			for(int k = j+1; k <= n; k ++) {
    				for(int l = k+1; l <= n; l ++) {
    					for(int o = l+1; o <= n; o ++) {
    						for(int i1 = o+1; i1 <= n; i1 ++){
    						for(int i2 = i1+1;i2<=n;i2++)	{
							
							
    long long x = a[i] & a[j] & a[k] & a[l] &a[i1]&a[i2];
    			    		if(x > maxn) maxn = x;}	     						
						}}
					}
				}
			}
		}
		cout << maxn;
		return 0;
	}
	
	if(m == 8&&m!=n) {
    	for(int i = 1; i <= n; i ++) {
    		for(int j = i+1; j <= n; j ++) {
    			for(int k = j+1; k <= n; k ++) {
    				for(int l = k+1; l <= n; l ++) {
    					for(int o = l+1; o <= n; o ++) {
    						for(int i1 = o+1; i1 <= n; i1 ++){
    						for(int i2 = i1+1;i2<=n;i2++)	{
							for(int i3 = i2+1;i3<=n;i3++) {
							
							
    long long x = a[i] & a[j] & a[k] & a[l] &a[i1]&a[i2]&a[i3];
    			    		if(x > maxn) maxn = x;}	     						
						}}}
					}
				}
			}
		}
		cout << maxn;
		return 0;
	}
	
		if(m == 9&&m!=n) {
    	for(int i = 1; i <= n; i ++) {
    		for(int j = i+1; j <= n; j ++) {
    			for(int k = j+1; k <= n; k ++) {
    				for(int l = k+1; l <= n; l ++) {
    					for(int o = l+1; o <= n; o ++) {
    						for(int i1 = o+1; i1 <= n; i1 ++){
    						for(int i2 = i1+1;i2<=n;i2++)	{
							for(int i3 = i2+1;i3<=n;i3++) {
							for(int i4 = i3+1;i4<=n;i4++) {
							
    long long x = a[i] & a[j] & a[k] & a[l] &a[i1]&a[i2]&a[i3]&a[i4];
    			    		if(x > maxn) maxn = x;}	     						
						}}}}
					}
				}
			}
		}
		cout << maxn;
		return 0;
	}
	
	if(m == 10&&m!=n) {
    	for(int i = 1; i <= n; i ++) {
    		for(int j = i+1; j <= n; j ++) {
    			for(int k = j+1; k <= n; k ++) {
    				for(int l = k+1; l <= n; l ++) {
    					for(int o = l+1; o <= n; o ++) {
    						for(int i1 = o+1; i1 <= n; i1 ++){
    						for(int i2 = i1+1;i2<=n;i2++)	{
							for(int i3 = i2+1;i3<=n;i3++) {
							for(int i4 = i3+1;i4<=n;i4++) {
							for(int i5 = i4+1;i5<=n;i5++) {
    long long x = a[i] & a[j] & a[k] & a[l] &a[i1]&a[i2]&a[i3]&a[i4]&a[i5];
    			    		if(x > maxn) maxn = x;}	    } 						
						}}}}
					}
				}
			}
		}
		cout << maxn;
		return 0;
	}


    maxn = a[1];
    for(int i =2; i <= n ;i++) {
    	maxn = a[i] & maxn;
	}
	cout << maxn;

	return 0;
}
