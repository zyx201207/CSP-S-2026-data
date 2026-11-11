#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[0]=INT_MAX;
	for(int i=1;i<=n;i++)
		for(int j=m;j>0;j--)
			f[j]=max(f[j],f[j-1]&a[i]);
	cout<<f[m];
	return 0;
}
