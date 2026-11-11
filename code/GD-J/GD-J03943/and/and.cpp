#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f[0]=a[i];
		for(int j=m;j>=1;j--){
			f[j]=max(f[j],f[j-1]&a[i]);
		}
	}cout<<f[m];
}
