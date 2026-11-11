#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5+5;
int n,m,a[MAXN],c;
vector<int> xuan;
bool flag[MAXN],f = 0;

void dfs(int c,int big,int small){
	if(f) return;
	if(c < 1){
		int sums = 0;
		bool fl = 1;
		for(int i=0 ; i<xuan.size() ; i++){
			sums += big-xuan[i];
			if(sums > m){
				fl = 0;
				break;
			}
		}
		if(fl) f = 1;
//		if(f){
//			for(int i=0 ; i<xuan.size() ; i++) cout << xuan[i] << ' ';
//			cout << endl << big << ' ' << small;
//			cout << endl;
//		}
		return;
	}
	if(big-small > m) return;
	for(int i=1 ; i<=n ; i++){
		if(flag[i]) continue;
		flag[i] = 1;
		xuan.push_back(a[i]);
		dfs(c-1,max(big,a[i]),min(small,a[i]));
		xuan.erase(xuan.begin()+xuan.size()-1); 
		flag[i] = 0;
		if(f) return;
	}
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1 ; i<=n ; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int left = 1,right = n;
	while(left <= right){
		int mid = (left+right)/2;
		f = 0;
		xuan.clear();
		memset(flag,0,sizeof(flag));
		dfs(mid,LONG_LONG_MIN,LONG_LONG_MAX);
		//cout << left << ' ' << mid << ' ' << right <<  ' ' << f <<endl;
		if(f) left = mid+1;
		else right = mid-1;
	}
	cout << right;
	return 0;
}
