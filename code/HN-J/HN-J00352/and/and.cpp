#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010];
bool cnt(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,cnt);
	n=a[0];
	for (int i=1;i<m;i++){
		n&=a[i];
	}
	cout << n;
}
