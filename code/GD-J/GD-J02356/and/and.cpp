#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],n,m;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
	
		int maxn=-1;
		for(int i = 1;i<=n;i++){
			maxn=max(a[i],maxn);
		}
		cout << maxn;
	}
	else if(m==n){
		int sum= a[1]&a[2];
		for(int  i= 3;i<=n;i++){
			sum = sum&a[i];
		}
		cout << sum;
	}
	else{
		int maxn=-1;
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout << maxn;
	}
	return 0;
}
