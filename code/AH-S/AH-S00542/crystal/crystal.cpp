#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m;
long long a[N], need[N], ma[N], l = 1, maxn = INT_MIN;
int main(){
	freopen("crystal.in","r", stdin);
	freopen("crystal.out","w", stdout);
	cin>> n>> m;
	for(int i = 1; i <= n; i ++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i ++){
		if(need[i - 1] + (ma[i - 1] * (a[i] - a[i - 1])) <= m){
			need[i] = need[i - 1] + (ma[i - 1] * (a[i] - a[i - 1]));
			ma[i] = ma[i - 1] + 1;
		}else{
			long long h = ma[i - 1];
			while(need[i - 1] + (h * (a[i] - a[i - 1])) > m){
				need[i - 1] -= (a[i - 1] - a[l]);
				l ++;
				h --;
			}
			need[i] = need[i - 1] + (h * (a[i] - a[i - 1]));
			ma[i] = h;
		}
		maxn = max(maxn, ma[i]);
	}
	cout<< maxn<< "\n";
	return 0;
} 
