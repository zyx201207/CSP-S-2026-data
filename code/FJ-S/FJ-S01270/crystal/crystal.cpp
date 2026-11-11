#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500500];
long long ans;
long long maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(long long i = n;i >= 1;i--){
		ans = 0;
		for(long long j = i-1;j > 0;j--){
			ans += (a[i]-a[j]);
			//cout << a[i]-a[j] << " ";
			if(ans > m){
				maxx = max(maxx,i-j);
				//cout << endl;
				break;
			}else if(ans == m){
				maxx = max(maxx,i-j+1);
				break;
			}
		}
	}
	cout << maxx;
	return 0;
} 
