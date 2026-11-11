#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long q[500005];
long long p[500005];
long long n,m;
bool chk(int t){
	for(int i = t;i <= n;i ++){
		if(q[i] - ((i - t)*a[i] - p[i - t])  <= m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i ++){
		q[i] = q[i - 1] + (a[i] - a[i - 1]) *(i - 1);
		p[i] = p[i - 1] + a[i];
		q[1] = 0;
	}
	int l = 0,r = n;
	while(l < r){
		//cout << l << r << endl;
		int mid = (l + r) / 2 + 1;
		if(chk(mid)){
			l = mid;
		}else{
			r = mid - 1 ;
		}
	}
	cout << l;
	return 0;
}

