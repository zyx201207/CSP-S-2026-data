#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N];
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	long long l = 1,r = 0;//º¥[l,r]”Îr+1∫œ≥… 
	long long sum = 0,cnt = 0;
	long long maxn = -1;
	while(r < n){
		if(l == r && r == n) break;
//		if(l == r && ((sum + m >= cnt * a[r + 1] && r < n) || r == 0) == false){
//			r++;
//			sum += a[r];
//			cnt++;
//		}
		while((sum + m >= cnt * a[r + 1] && r < n) || r == 0){
			r++;
			sum += a[r];
			cnt++;
			//cout << l << r << 1 <<  endl;
		}
		
		maxn = max(maxn,r - l + 1);
		if(r != n)
		{
			while(sum + m < cnt * a[r +1] && l <= r){
				sum -= a[l];
				l++;
				cnt--;
				//cout << l << r << 2 << endl;
			}
			maxn = max(maxn,r - l + 2);
		}
		else{
			while(sum + m < cnt * a[r] && l <= r){
				sum -= a[l];
				l++;
				cnt--;
				//cout << l << r << 3 << endl;
			}
			maxn = max(maxn,r - l + 1);
			break;
		}
	}
	if(maxn >= n) maxn = n;
	cout << maxn; 
	return 0;
	
}
