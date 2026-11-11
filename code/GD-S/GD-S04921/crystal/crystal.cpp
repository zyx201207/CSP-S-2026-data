#include<bits/stdc++.h>
using namespace std;

const int N = 500005;
long long n,m;
long long a[N];
int mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	
	if(n >= 10000){
		for(int i = a[1];i <= a[n];i++){
			int mid = -1;
			for(int j = 1;j <= n;j++){
				if(a[j] > i){
					mid = j - 1;
					break;
				}
			} 
			long long sum = 0;
			int cnt = 0;
			for(int j = mid;j >= 1;j--){
				sum += (i - a[j]);
				if(sum >= m){
					if(sum == m) cnt++;
					break;
				}
				cnt++;
			}
			mx = max(mx,cnt);
		}
	}else{
		for(int i = 1;i <= n;i++){
			long long sum = 0;
			int cnt = 0;
			if(n - i + 1 <= mx || a[mx + i - 1] - a[i] > m) continue;
			for(int j = i;j <= n - 1;j++){
				sum += 1LL * (a[j + 1] - a[j]) * (j - i + 1);
				if(sum <= m) cnt++;
				else break;
			}
			mx = max(mx,cnt + 1);
		}
	}
	cout << mx;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
