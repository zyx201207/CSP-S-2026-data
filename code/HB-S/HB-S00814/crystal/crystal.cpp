#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,m,a[MAXN];
int ans=INT_MIN;
int solve(int id){
	int t=m,tt[MAXN],sum=1;
	for (int i=1;i<=n;i++) tt[i]=a[i];
	for (int i=id+1;i<=n && t>0;i++){
		if ((a[i]-a[i-1])*(i-id)<=t){
			t-=(a[i]-a[i-1])*(i-id);
			for (int j=id;j<i;j++) tt[j]=a[i];
		}
		else break;
	}
	for (int i=id+1;i<=n;i++){
		if (tt[i]==tt[i-1]) sum++;
		else break;
	}
	return sum;
}
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) {
		ans=max(ans,solve(i));
	}
	cout<<ans;
	return 0;
}
