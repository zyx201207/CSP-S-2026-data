#include<bits/stdc++.h>
#define int long long

using namespace std;
int n,m;
int a[500007];
int s[500007];

bool check(int k){
	int cst=1000000000000000007;
	for(int i=k;i<=n;++i){
		cst = min(cst,a[i]*i-s[i]+s[i-k]);
	}
	//cout << cst << '\n';
	if(cst>m) return 0;
	else return 1;
}

void sol(){
	int l=1,r=n,mid;
	int ans=1;
	while(l<=r){
		mid = (l+r)/2;
		//cout << mid << ' ';
		if(check(mid)){
			l = mid+1;
			ans = mid;
		}else{
			r = mid;
		}
	}
	cout << ans;
	return;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool fl = 1,fl2=1;
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		if(a[i]!=i) fl=0;
		if(i!=1&&a[i]-a[i-1]!=a[2]-a[1]) fl2 = 0;
	}
	if(fl){
		int i=n/2;
		while((i-1)*(i)/2>n) i--;
		cout << i;
		return 0;
	}
	if(fl2){
		int i=n/2,dert=a[2]-a[1];
		while((i-1)*(dert)*(i)/2>n)i--;
		return 0;
	}
	sort(a+1,a+n+1);
	int de = -a[1];
	for(int i=1;i<=n;++i){
		a[i] = a[i] + de;
		s[i] = s[i-1]+a[i];
		//cout << a[i] << ' ' << s[i] << '\n';
	}
	sol();
}
