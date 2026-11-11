#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 500005
int a[maxn],n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int sum=0;
	bool flag;
	for(int i=2;i<=n;i++){
		int c=(i-1)*(a[i]-a[i-1]);
		sum+=c;
		if(m<sum){
			cout << i-1,flag=true;
			break;
		}
	}
	if(!flag) cout << n;
	return 0;
}
