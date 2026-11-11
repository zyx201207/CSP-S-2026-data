#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010],maxx,f[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)f[i]=a[i];
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			f[j]=max(f[j-1],f[j]&a[j-1]);
		}
		for(int j=1;j<=n;j++)a[j]=f[j];
	}
	cout<<f[n];
	return 0;
}

