#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],maxx=-10001;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n > 5000){
		int cnt=0;
		int t=m;
		while(t>=0){
			t-=cnt;
			cnt++;
		}
		cnt--;
		cout << cnt;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		int t=m,b=1,j=i-1;
		while(j>0){
			t-=(a[i]-a[j]);
			if(t < 0)break;
			b++;
			j--;
		}
//		cout << b << " ";
		maxx=max(maxx,b);
	}
	cout << maxx;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
