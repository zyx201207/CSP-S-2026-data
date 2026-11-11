#include <bits/stdc++.h>
#define MAXN 2000005
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[MAXN];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	reverse(a,a+n);
	int ans=0;
	for(int i=1;i<m;i++){
		a[i]=a[i-1]&a[i];
		ans=a[m-1];
	}
	cout<<ans;
	return 0;
} 
