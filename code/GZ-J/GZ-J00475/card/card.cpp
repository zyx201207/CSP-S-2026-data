//GZ-J00475 遵义市第四中学 卢语涵
#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005], ans[500005];
long long sum;
bool b[500005];
stack<long long> stk;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(!b[a[j]]){
				stk.push(a[j]);
				b[a[j]] = true;
				sum++;
			}else{
				while(stk.top() != a[j]){
					b[stk.top()] = 0;
					stk.pop();
					sum--;
				}
			}
		}
		long long temp;
		for(int j = 0; j < sum; j++){
			temp = stk.top();
			ans[temp]++;
			stk.pop();
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
