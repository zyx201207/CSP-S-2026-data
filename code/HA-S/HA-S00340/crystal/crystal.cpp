//crystal
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[500005],ans,cnt;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i ++){
		cin>>a[i];
	}
	if (n <= 5000){//±©Á¦ 
		int maxx = -0x7fffffff;
		sort(a + 1,a + n + 1);
		for (int i = 1;i <= n;i ++){
			int tmp = m,s = 1;
			for (int j = i - 1;j >= 1;j --){
				if (tmp >= a[i] - a[j]){
					tmp -= a[i] - a[j];
					s ++;
				}
			}
			maxx = max(maxx,s);
		}
		cout<<maxx;
	}else{//´íÎóµÄÌ°ÐÄ 
		sort(a + 1,a + n + 1);
		bool b = 1;
		for (int i = 1;i <= n;i ++){
			if (a[i] != a[i - 1] && b && i > 1){
				cnt = i - 1;
				b = 0;
			}
		}
		while (m > 0){
			int nd = (a[cnt + 1] - a[cnt]) * cnt;
			if (nd <= m){
				m -= nd;
				for (int i = cnt + 1;i <= n;i ++){
					if (a[i] != a[cnt + 1]){
						cnt = i - 1;
						break;
					}
				}
			}else{
				break;
			}
		}
		cout<<cnt;
	}
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

7 5
3 9 9 9 9 9 10
*/
