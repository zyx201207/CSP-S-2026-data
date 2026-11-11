#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],f[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i]=a[i];
	}
	for(int i=m;i>=1;i--){
		for(int j=1;j<=n;j++){
			f[i]=f[i-1]&a[j];
			for(int k=1;k<j;k++){
				f[i]=max(f[i],f[k]&a[j]);
			}
		}
	}
	cout<<f[m];
	return 0;
}
