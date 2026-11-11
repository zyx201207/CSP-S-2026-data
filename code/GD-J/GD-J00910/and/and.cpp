#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N],n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		a[x]++;
	}
	for(int i=2000000;i>=1;i--){
		if(a[i]) m-=a[i];
		if(m<=0){
			cout << i;
			return 0;
		}
	}
	return 0;
}
