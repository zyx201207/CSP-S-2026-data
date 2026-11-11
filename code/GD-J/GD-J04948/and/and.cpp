#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],f[200005],maxn=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(f[j-1]==0) f[j]=max(f[j],a[i]);
			else f[j]=max(f[j],f[j-1]&a[i]);
		}
	}
	cout<<f[m];
}
