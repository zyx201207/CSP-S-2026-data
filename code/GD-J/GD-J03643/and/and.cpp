#include <bits/stdc++.h>
#define int long long
#define N 200005
#define M 32
using namespace std;

int n,m;
int a[N];
string erj[N];
int num[M+5];
int ans;
int maxl = 0;

bool cmp(string x,string y){
	return x > y;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;++i) cin >> a[i];
	for (int i=1;i<=n;++i){
		int j = 0;
		int u = a[i];
		string t = "";
		while (u){
			if (u % 2 == 1) t = "1" + t;
			else t = "0" + t;
			j++;
			u /= 2;
		}
		erj[i] = t;
		maxl = max(maxl,j);
	}
	for (int i=1;i<=n;++i){
		int len = erj[i].size();
		for (int j=1;j<=maxl-len;++j) erj[i] = "0" + erj[i]; 
	} 
	
	for (int i=1;i<=n;++i){
		for (int j=0;j<maxl;++j){
			if (erj[i][j] == '1') num[j]++;
		}
	}
	
	int idx = 0;
	while (num[idx] < m){
		for (int i=1;i<=n;++i){
			erj[i] = erj[i].substr(0,idx) + "0" + erj[i].substr(idx+1,maxl-idx-1);
		}
		idx++;
	}
	sort(erj+1,erj+1+n,cmp);
	
	
	//for (int i=1;i<=m;++i) cout <<erj[i] << ' ';
	
	int k = 1;
	for (int j=maxl-1;j>=0;--j){
		bool is_one = 1;
		for (int i=1;i<=m;++i){
			if (erj[i][j] == '0'){
				is_one = 0;
				break;
			}
		}
		if (is_one == true){
			ans += k;
		}
		k *= 2;
	}
	cout << ans;
	
	
	
	return 0;
} 
