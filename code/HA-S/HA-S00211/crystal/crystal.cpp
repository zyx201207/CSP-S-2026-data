#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 5e6 + 10;
int arr[N], n, m;
int sum[N], sup[N];
int inv[N];
int tot;
main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n ;++i){
		cin >> arr[i];
	}
	sort(arr+1,arr+1+n);
//	sort(arr+1,arr + 1 + n);
//	for(int i = 2;i <= n;++i){
//		inv[i] = arr[i] - arr[i - 1];
//	}

//	for(int i = 2;i <= n;++i){
//		if(tot<=m){
//			tot+=inv[i];
//			q.push(inv[i]);
//		if(inv[i] > q.top() && tot - q.top() + inv[i] <= m){
//			q.pop();
//			q.push(inv[i]);
//			tot+=inv[i] - q.top();
//		}
//	}
//	cout<<q.size() - 1<<endl;
	for(int i = 1;i<=n;++i){
		sum[i] = sum[i - 1] + arr[i];
		sup[i] = abs(sum[i] - i * arr[i]);
	}
	int pos = upper_bound(sup+1,sup+1+n,m) - sup - 1;
	cout<<pos<<endl;
}