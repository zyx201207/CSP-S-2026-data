#include <bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1e9,minn=1e9,maxcnt=-1e9;
long long a[500020];
long long isok(long long x){
	long long cnt=0,cha=0;
	for(long long i=1;i<=n;i++){
		if(a[i]<=x && cha+x-a[i]<=m){
			cnt++;
			cha+=x-a[i];
		}
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	for(long long i=minn;i<=maxn;i++){
		maxcnt=max(isok(i),maxcnt);
	}
	cout << maxcnt;
	return 0;
}
