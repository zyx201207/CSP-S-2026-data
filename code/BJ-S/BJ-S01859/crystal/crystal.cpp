#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,ans;
long long m,a[N],x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	x = a[2] - a[1];
	for(int k = 2;k < n;k ++){
		if(a[k + 1] - a[k] != x){
			for(int i = 1;i <= n;i ++){
				int cnt = i;
				long long dm = m;	
				for(;cnt < n;){
					if((a[cnt + 1] - a[cnt]) * (cnt - i + 1) <= dm){
						dm -= (a[cnt + 1] - a[cnt]) * (cnt - i + 1);
						cnt ++;
					}
					else{
						break;
					}
				}
				ans = max(ans,cnt - i + 1);
			}
			cout << ans;
			return 0;
		}
	}
	for(;ans < n;){
		if((a[ans + 1] - a[ans]) * ans <= m){
			m -= (a[ans + 1] - a[ans]) * ans;
			ans ++;
		}
		else{
			break;
		}
	}
	cout << ans;
	return 0;
}
