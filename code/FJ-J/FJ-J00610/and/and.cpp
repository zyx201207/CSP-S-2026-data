#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,ans;
unsigned long long num[200010];
bool vis[200010];
void dfs(unsigned long long k,unsigned long long x){
	if(k == 0){
		ans = max(x,ans);
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(k - 1,x & num[i]);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool qA = true,qB = true;
	if(pow(2,log(n) / log(2)) != n){
		qB = false;
	}
	for(int i = 1;i <= n;i++){
		cin>>num[i];
		if(pow(2,log(num[i] + 1) / log(2)) - 1 != num[i]){
			qA = false;
		}
		if(num[i] != i - 1){
			qB = false;
		}
	}
	if(qA){
		sort(num + 1,num + n + 1);
		cout<<num[n - m + 1];
		return 0;
	}
	if(qB){
		sort(num + 1,num + n + 1);
		cout<<num[n] & (((unsigned long long)pow(2,m - 1) / 2) ^ (unsigned long long)-1);
		return 0;
	}
	dfs(m,-1);
	cout<<ans;
	return 0;
}

