#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int a[200005];

bool is_int(double x){
	return x-(int)x==0?1:0;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int k=0;
	while(is_int(log2(a[n-k]))){
		k++;
	}
	int ans = a[n-k];
	k=0;
	for(int i=n-1;i>n-m;i--){
		if(is_int(log2(a[i]))){
			k++;
			continue;
		}
		ans = ans & a[i-k];
	}
	cout << ans;
	return 0;
}
