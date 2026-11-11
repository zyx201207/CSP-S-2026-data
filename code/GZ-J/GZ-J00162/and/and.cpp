//GZ-J00162 遵义市第十二中学 田家锜 
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long sum[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=2;i<=m;i++){
		a[i]=a[i-1]&a[i];
	}
	cout<<a[m];
	return 0;
}
