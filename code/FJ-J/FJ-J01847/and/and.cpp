#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[50000005],b[50000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n];
    else cout<<a[n-1];

	return 0;
}
