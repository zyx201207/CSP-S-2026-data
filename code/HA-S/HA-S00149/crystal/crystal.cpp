#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+5;
int n,m;
int a[N];
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n>>m;
	for (int i=1;i<=n;i++){
		cin >>a[i];
	}sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		int mm=m,x=0;
		for (int j=1;j<=i;j++){
			x+=(a[i]-a[j]);
			if (x>m){
				cout <<ans;
				return 0;
			}ans=max(ans,j);
		}
	}
	cout <<ans<<endl;
	return 0;
}/*
5 5 
1 2 4 8 9
*/
/*
5 8 
-3 -1 2 2 7
*/
/*
5 8
-3 1 2 3 5
*/
