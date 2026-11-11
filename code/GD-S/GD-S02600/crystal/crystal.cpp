#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n,m,a[100005],maxn=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll mm=m,s=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]==a[j]){
				s++;
				continue;
			}
			if(a[j]+mm<a[i])break;
			mm-=(a[i]-a[j]);
			s++;
		}
		maxn=max(s,maxn);
	}
	cout << maxn;
	return 0;
}
/*
5 5
1 2 4 8 9
*/

/*
5 8
-3 -1 2 2 7
*/
