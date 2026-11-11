#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2E5+7;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	int op=0;
	for(int i=30;i>=0;i--){
		op^=(1<<i);
		int cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]&op)==op) cnt++;
		}
		if(cnt<m) op^=(1<<i);
	}
	cout << op;
	return 0;
}

