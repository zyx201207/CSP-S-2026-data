#include<bits/stdc++.h>
using namespace std;
int a[200005];
int m;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ge,t;
	cin >> ge >> t;
	while(t--){
		int n,d,ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n;i++){
			cin >> a[i];
		}
		    long long k = 2;
		    for(int k = 2;k <= m;k++){
		    	if(a[k] - a[k - 1] <= d&& k != m)
		    		return 0;
				long long j = k + 2;
				if(k != m){
					k--;
				}
		        for(int i = 2 ; i <= n-1;i++){
			        if(a[i + 2] - a[i] <= d && a[i + 2] - a[i - 1]<=d && a[i + 2] - a[i - 1] > d){
				        ans+=(i - 1)*(n - i -1);
				        j = i;
			        }
		        }
		        k++;
		        k += k;
	        }
		    cout << ans << "\n";
	    }
	return 0;
}
