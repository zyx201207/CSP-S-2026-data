#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int n,m,a[N],f[N];
int main(){
	freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	f[1] = a[1];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m - 1;j++){
			f[i] = max(f[i],f[j] & a[j]);
		}
		for(int j = n;j >= i + 1;j--){
			f[j] = max(f[i],a[i] & a[j]);
		}
	}
	cout<<f[n];
	return 0;
} 
