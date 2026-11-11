#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-m+1;i++){
		long long k=a[i];
		for(int j=i+1;j<=n-m+2;j++){
			for(int ij=1;ij<m;ij++){
				k=k&a[j];
			}
		}
		ans=max(ans,k);
	}
	cout<<ans;
	return 0;
}
