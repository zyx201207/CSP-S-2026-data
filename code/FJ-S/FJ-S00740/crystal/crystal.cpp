#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500002;
int a[N];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ijk = 1;
	int ans = 1;
	int ned = a[1];
	int num = 1;
	int last = a[1];
	int had = 0;
	for(int i = 2; i <= n; i++){
		int temp = (a[i] - last) * num;
		had += temp;
		while(had > m){
			had -= (a[i] - a[ijk]);
			ijk ++;
			num--;
		}
		num ++;
		ans = max(ans,num);
		last = a[i];
	}
	cout<<ans;
	return 0;
}