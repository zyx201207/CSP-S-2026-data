#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
const int O=1024*1024*1024*2-1;
int a[N],f[N];
signed main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[0]=O;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			f[j]=max(f[j],f[j-1]&a[i]);
		}
	}
	cout<<f[m];
	return 0;
}
