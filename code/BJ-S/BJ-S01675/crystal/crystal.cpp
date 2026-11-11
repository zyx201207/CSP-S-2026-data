#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
bool same = true;
bool dc = true;
long long m,ans = 1,d;
long long a[maxn];
long long qz[maxn];
long long cost[5500][5500];
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	qz[0] = 0;
	qz[1] = a[1];
	for(int i = 2;i <= n;i ++) cin >> a[i];
	sort(a+1,a+n+1);
	d = a[2] - a[1];
	for(int i = 2;i <= n;i ++){
		if(a[i] - a[i-1] != d) dc = false;
		qz[i] = a[i] + qz[i-1];
	}
	if(n <= 5500){
		for(int i = 1;i < n;i ++){
			for(int j = i+1;j <= n;j ++){
				cost[i][j] = a[j] * (long long)(j-i+1) - (qz[j] - qz[i-1]);
				if(cost[i][j] <= m){
                    ans = max(ans,(long long)j-i+1);
				}
			}
		}
        cout << ans;
	}else if(dc){
        long long c = 0;
        for(int i = 2;i <= n;i ++){
            if((c + (i-1) * d) <= m){
                c += (i-1)*d;
                ans ++;
            }else{
                break;
            }
        }
        cout << ans;
	}
	retun 0;
}
