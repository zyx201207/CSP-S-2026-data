#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[200010];
char c[200010];
int cnt = 0;
int l,r;
int ls,rs;

void change(bool is_cnt){
	if(ls < rs){
		if(is_cnt) cnt += ls;
		l++;
		rs -= ls;
		ls = a[l];
	}else if(ls > rs){
		if(is_cnt) cnt += rs;
		r--;
		ls -= rs;
		rs = a[r];
	}else{
		if(is_cnt) cnt += rs;
		l++;
		r--;
		ls = a[l];
		rs = a[r];
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i] >> c[i];
	}
	l = 1,r = n;
	ls = a[l],rs = a[r];
	while(l <= r){
		if(c[l] == c[r]){
			change(0);
		}else{
			change(1);
		}
	}
	cout << cnt << '\n';
	return 0;
}
