#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n,m;
int a[N];
int sum[N],s[N],c[N],pre[N];
bool abc(int x,int y){
	return x > y;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i<=n;i++){
    	cin >> a[i];
    }
    sort(a+1,a+1+n,abc);
    //int pre = 0;
    for (int i = 2;i<=n;i++){
    	c[i-1] = a[i-1]-a[i];
    	//cout << c[i] <<endl;
    	pre[i-1] = pre[i-2]+c[i-1];
    	sum[i-1] = pre[i-1]*(n-i+1);
    }
    for (int i = n;i > 1;i--){
    	s[n-i+1] = s[n-i]+c[i-1]*(n-i+1); 
    	//cout << c[i-1] <<endl;
    }
//    for (int i = 1;i<n;i++){
//    	cout << sum[i] << " " << s[i] <<" " <<pre[i] <<endl;
//    }
	int maxx = -0x3f;
    for (int i = 1;i<n;i++){
    	int mx = 0,mn = 0;
    	int l = i,r = n-1;
    	int ans = 0;
    	//cout << a[i] <<"}}" <<endl;
    	while(l < r){
    		//cout << i;
    		//ans++;
    		int mid = (l+r)/2;
    		int w = s[n-i]-(sum[mid+1]-pre[i-1]*ans)-s[max(n-mid-2,0ll)];
    		//cout << l <<"|" << r<<"|" << w <<endl;
    		if (w > m){
    			if (mx == 0 && mn == 0) mx = 1;
    			if (mn){//
    				maxx = max(l-i,maxx);
    				break;
    			}
    			if (r-l == 1){
    				break;
    			}
    			r = mid;
    			ans++;
    		}else if (w < m){
    			if (mx == 0 && mn == 0) mn = 1;
    			if (mx){
    				//cout << 1;
    				maxx = max(mid-i+2,maxx);
    				break;
    			}
    			if (r-l == 1){
    				//cout << i <<"!!";
    				maxx = max(r-i+2,maxx);
    				//cout << 1 <<endl;
    				break;
    			}
    			l = mid;
    			ans--;
    		}else if (w == m){
    			//cout << "!!";
    			//cout << i << <<endl;
    			maxx = max(mid-i+2,maxx);
    			break;
    		}
    	}
    }
    cout << maxx;
    return 0;
}
