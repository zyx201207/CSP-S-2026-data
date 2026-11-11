#include <bits/stdc++.h> 

using namespace std;

 long long a[500005],ans;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ){
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
//	for (int i = 1; i <= n; i ++ ){
//		cout <<"第"<<i<< "个："<< a[i];
//	}
	long long maxv = 0;long long v;long long k;
	for (int i = 1; i <= n; i ++){
		v = a[i];
		for (int j = i;a[j] == v;j++){
			maxv ++;
		}
		k = m;
		//cout <<"第"<<i<< "次："<<maxv << endl;
		for (int j = i - 1; j >= 1; j --){
			if(k-(a[i] - a[j]) >= 0){
				maxv ++;
				k -= (a[i]-a[j]);
				//cout << maxv << " "<< k << endl;
			}}
		//cout << maxv << endl;
		ans = max(maxv, ans);
		maxv = 0;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
