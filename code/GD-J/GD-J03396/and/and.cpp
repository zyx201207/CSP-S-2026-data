#include <bits/stdc++.h>
using namespace std;
const long long MAXN=pow(2,20)-1;
long long n,m,a[1000005],ans,sum=MAXN,sum1,sum2;
bool vis[1000005];
bool xx(long long l){
	for(int i=1;;i*=2){
		if (l==i-1) return 1;
		if (i>l) return 0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]=i-1) sum1++;
		if (xx(a[i])==1) sum2++;
		ans=max(a[i],ans);
	}
	if (m==1){
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	if (sum1==n) {
		for(int i=n;i>=n-m;i--) sum&=a[i];
		cout<<sum;
		return 0;
	}
	if (sum2==n){
		cout<<a[n-m];
		return 0;
	}
	ans=0;
	long long l=0;
	cout<<ans;
	return 0;
}
