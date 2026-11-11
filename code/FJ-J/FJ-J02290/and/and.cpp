#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int ans=pow(2,31)-1;
	for(int i=1;i<=m;i++){
		int mx=0,wz;
		for(int j=1;j<=n;j++){
			if((a[j]&ans)>mx){
				wz=j;
				mx=(a[j]&ans);
			}
		}
		ans=(a[wz]&ans);
		a[wz]=0;
	}
	cout << ans;
	
	return 0;
}
