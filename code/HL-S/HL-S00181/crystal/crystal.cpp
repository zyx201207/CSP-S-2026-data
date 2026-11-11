#include <bits/stdc++.h>
using namespace std;

long long n,m;
const int M = 5e5+10;
long long a[M]={};

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i= 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long ans = -1;
	
	for(int i = n;i >= 1;i--){
		long long cnt = 1;
		long long temp = 0;
		for(int j = i-1;j >= 1;j--){
			if(temp + (a[i] - a[j]) > m){
//				ans = max(ans,cnt);
				break;
			}
			else{
				temp += (a[i] - a[j]);
				cnt++;
			}
//			cout << temp << " " << cnt << endl;
			ans = max(ans,cnt);
		}	
	}
	cout << ans;
	return 0;
}
