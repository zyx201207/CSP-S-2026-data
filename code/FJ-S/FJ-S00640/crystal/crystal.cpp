#include <bits/stdc++.h>
using namespace std;

const int N=5e5+2;
int n;
long long m,p[N],sum[N];

bool check(int x){
	for(int i=1;i+x-1<=n;i++)
		if(p[i+x-1]*(x-1)-(sum[i+x-2]-sum[i-1])<=m) return 1;
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> p[i];
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+p[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout << l;
	return 0;	
}
