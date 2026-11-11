#include<bits/stdc++.h>
#define int long long
#define MAXN 5000005
using namespace std;
int a[MAXN],n,ans,add[MAXN];
int c[MAXN],sum,m;
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<n;i++){
		c[i] = a[i] - a[i + 1];
		add[i] = add[i - 1] + c[i];
	}
	int l=1,r=1,sum = c[1],ans = 1;
	for(;l<n;l++){
		sum -= c[l - 1] * (r - l + 1);
		while(r < n - 1 && (sum + add[r + 1] - add[l - 1] <=m)){
			sum += add[r + 1] - add[l - 1];
			r ++;
		}
		ans = max(ans,r - l + 2);
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}/*
5 5
1 2 4 8 9
*/
