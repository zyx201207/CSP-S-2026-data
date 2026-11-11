#include<bits/stdc++.h>
using namespace std;
int main (){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	long long zueduo=0;
	int n,m;
	cin >> n >> m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		long long shu=m,zd=0;
		for(int j=1;j<=n;j++){
				if(a[j]==a[i]){
				    zd++;
				}
				else if(a[j]<a[i]&&a[i]-a[j]<=shu){
					zd++;
					int q=a[i]-a[j];
					shu-=q;
				}
		}
		zueduo=max(zd,zueduo);
	}
	cout << zueduo;
	return 0;
}
