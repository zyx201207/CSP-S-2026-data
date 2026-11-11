//GZ-J00317 遵义市第四初级中学 王培祯 
#include <bits/stdc++.h>
using namespace std;
int ans,a[200001],n,m;
long long a1,b1,c1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
//	while(a[i]!=0){
//		b1+=a[i]%2;
//		a[i]/=2;
//	}
//	for(int i=n-1;i>=n-m+1;i++){
//		int w=1;
//		while(a[i]!=0){
//			b1+=a[i]%2;
//			a[i]/=2;
//		}
//	}
	cout<<a[n-m];
	return 0;
}

