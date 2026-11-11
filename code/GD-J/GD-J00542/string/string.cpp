#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
char c[N];
stack<pair<long long, char>> sta1;
stack<pair<long long, char>> sta2;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long sum = 0;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	long long m = sum / 2,summ = 0, k=1;
	while(summ < m){
		if(summ + a[k] <= m){
			sta1.push({a[k],c[k]});
			k++;
		}
		else{
			sta1.push({m - summ,c[k]});
			break;
		}
	}
	summ = 0,k = n;
	while(summ < m){
		if(summ + a[k] <= m){
			sta1.push({a[k],c[k]});
			k--;
		}
		else{
			sta1.push({m - summ,c[k]});
			break;
		}
	}
	long long ans = 0;
	while(!sta1.empty()&&!sta2.empty()){
		long long e = sta1.top().first;
		char r = sta1.top().second;
		long long t = sta2.top().first;
		char y = sta2.top().second;
		if(e < t){
			sta2.top().first -= e;
			sta1.pop();
			if(r == y){
				continue;
			}
			else{
				ans += e;
			}
		}
		else{
			sta1.top().first -= t;
			sta2.pop();
			if(r == y){
				continue;
			}
			else{
				ans += t;
			}
		}
	}
	cout << ans;
}
