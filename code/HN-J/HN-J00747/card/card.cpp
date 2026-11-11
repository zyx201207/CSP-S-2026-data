#include<bits/stdc++.h>
//long long
#define endl '\n';
using namespace std;

long long n,m,ans[300050],x[500050],B[300050],a[300050],r[300050],f[500050];
stack<long long> stk;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	long long t = m;
	for(long long i = 1;i <= n;i ++){
		cin >> x[i];
	}
	for(int i = n;i >= 1;i --){
		if(!B[x[i]]){
			B[x[i]] = t;
			r[t] = x[i];
			t--;
		}
		x[i] = B[x[i]];
	}
	for(long long i = 1;i <= n;i ++){
		while(stk.size() && x[stk.top()] < x[i]){
			stk.pop();
		}
		if(stk.size())
		f[i] = stk.top();
		stk.push(i);
	}
	for(long long i = 1;i <= n;i ++){
		ans[r[x[i]]] += i - f[i];
	}
	for(long long i = 1;i < m;i ++){
		cout << ans[i] << ' ';
	}
	cout << ans[m];
	return 0;
}

