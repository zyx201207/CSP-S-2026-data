#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200024],b[200024];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	bool f;
	long long temp,ans=0;
	for(int i = 1;i <= m;i++){
		if(ans==0)ans=a[i];
		else ans&=a[i];
	}
	cout << ans;
	return 0;
}
