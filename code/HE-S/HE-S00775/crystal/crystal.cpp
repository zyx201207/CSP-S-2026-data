#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10,INF=-INT_MAX;
int a[N],sun[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++) cin>>a[i];
	sort(a,a+n);
	int maxn=INF;
	for(int i=0; i<n; i++) {
		int cnt=1;
		if(i!=0&&a[i]==a[i-1]) continue;
		for(int j=0; j<n; j++) sun[j]=abs(a[j]-a[i]);
		sort(sun,sun+n);
		for(int mm=m; mm>0; cnt++)
			if(mm>sun[cnt]) mm-=cnt;
			else break;
		maxn=max(maxn,cnt-1);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
