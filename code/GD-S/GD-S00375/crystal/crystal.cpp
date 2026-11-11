#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long maxx = -9e18;
long long a[1100000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for (long long i = 1;i <= n;i++){
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}sort(a+1,a+n+1);
	long long l = 1,r = 1;
	long long prs = 0;
	long long en = l - r + 1;
	long long add = 0;
	long long minus = 0;
	long long maxv = LLONG_MIN;
	long long backup = LLONG_MIN;
	while(r<=n){
		backup = LLONG_MIN;
		if(r == n)break;
		en = r - l + 1;
		minus = 0;
		add = 0;
		

		
		while(prs <= m&&r<=n){
			r++;
			en = r - l + 1;
			add = (a[r]-a[r-1])*(en-1);
			prs = prs + add;
			maxv = max(maxv,backup);
			backup = en;
//			cout << "l:" << l << endl;
//		cout << "r:" << r << endl;
//		cout << "en:" << en << endl ;
//			
//			cout << "add:" << add << endl;
//			cout << "prs:" <<prs << endl;
//			cout << "maxv:" << maxv << endl<< endl;
		}
		

		
		while(prs > m&&l<=r){
			l++;
			en = r - l + 1;
			minus = a[r]-a[l-1];
			prs = prs - minus;
			
//			cout << "l:" << l << endl;
//		cout << "r:" << r << endl;
//		cout << "en:" << en << endl;
//			
//			cout << "minus:" << minus << endl;
//			cout << "prs:" <<prs << endl << endl;
		}maxv = max(maxv,en);
		
		
	}cout << maxv;
	
	/*
5 8
-3 -1 2 2 7
	*/
	/*
5 5
1 2 4 8 9
	*/
	return 0;
} 
