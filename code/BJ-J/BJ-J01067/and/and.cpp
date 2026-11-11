#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m,a[2005];
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
        cin >> a[i];
	}
	if(m == 1){
        int maxn = -1;
        for(int i = 1;i <= n;i++){
            maxn = max(maxn,a[i]);
        }
        cout << maxn;
	}
	else if(m == n){
        int cnt = a[1];
        for(int i = 2;i <= n;i++){
            cnt = cnt & a[i];
        }
        cout << cnt;
	}
	else if(m == 2){
        int maxn = -1;
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                maxn = max(maxn,a[i] & a[j]);
            }
        }
        cout << maxn;
	}
	else if(m == n-1){
        int q[200005],h[200005];
        q[1] = a[1];
        for(int i = 2;i <= n;i++){
            q[i] = q[i-1] & a[i];
        }
        h[n] = a[n];
        for(int i = n-1;i >= 1;i--){
            h[i] = h[i+1] & a[i];
        }
        int maxn = -1;
        for(int i = 1;i <= n;i++){
            int cnt = 0;
            if(i-1 > 0 && i+1 <= n){
                cnt += q[i-1] & h[i+1];
            }
            else if(i-1 > 0){
                cnt += q[i-1];
            }
            else if(i-1 > 0){
                cnt += h[i+1];
            }
            maxn = max(maxn,cnt);
        }
        cout << maxn;
	}
	else{
        int minn = 67676767;
        for(int i = 1;i <= n;i++){
            minn = max(minn,a[i]);
        }
        cout << minn;
	}
	return 0;
}
