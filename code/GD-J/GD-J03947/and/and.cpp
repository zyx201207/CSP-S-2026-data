#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200005];
long long zs(long long a,long long b){
	long long zh[200005],zh1[200005];
	long long c=a,d=b,xs=1;
	while(c!=0 && d!=0){
		if (c%2==d%2){
			zh1[xs]=1;
		}
		xs++;
		c/=2;
		d/=2;
	}
	long long s;
	long long js=1;
	for (int i=1; i<=xs; i++){
		s+=js*zh1[i];
		js*=2;
	}
	return s;
}
int main(){
	long long zz;
	long long ma;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	for (int i=1; i<=n; i++){
		zz=a[i];
		for (int j=2; j<=m; j++){
			zz=zs(zz,a[j]);
		}
		ma=max(zz,ma);
	}
	cout<<ma;
	
	return 0;
}
