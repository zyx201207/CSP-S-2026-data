#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m,ans = 1,a[N];
int s[N];
bool check(int nw,int x){
	int tmp = s[nw]-(s[x]+(x-1)*(a[nw]-a[x]));
	return (tmp<=m);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i = 2;i<=n;i++){
		s[i] = s[i-1]+(i-1)*(a[i]-a[i-1]);
		int l = 1,r = i;
		while(l<r){
			int mid = (l+r)>>1;
			if(check(i,mid))
				r = mid;
			else
				l = mid+1;
		}
		ans = max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 5
1 2 3 4 5

5 6
2 4 6 8 10*/
