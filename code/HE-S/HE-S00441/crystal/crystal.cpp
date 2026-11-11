#include <bits/stdc++.h>
using namespace std;
long long m,a[500005],b[500005],c[500005],ans=1;
bool check(int ii,int jj,long long mm){
	long long sum=a[jj]*(jj-ii+1)-c[jj]+c[ii-1];
	if (sum <= m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin >> n;
	cin >> m;
	for (int i =1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	c[1]=a[1];
	bool o=1;
	for (int i=2;i<=n;i++){
		b[i] = a[i]-a[i-1];
		if(i >= 3){
			if(b[i]!=b[i-1]) o =0;
		}
		c[i] = c[i-1]+ a[i];
	}
	if(o){
		for (long long i=2;i<=n;i++){
			if (b[3]*i*(i-1) <= m*2) ans=i;
			else break;
		}
		cout << ans;
		return 0;
	}
	for (long long i=1;i<=n;i++){
		for (long long j=i+1;j<=n;j++){
			if(check(i,j,m)) ans = max(ans,j-i+1);
		}
	}
	cout << ans;
	return 0;
}
