#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5+5;
int a[N];
int cmp(int x,int y){
	return x > y;
}signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}sort(a+1,a+n+1,cmp);
	cnt = a[1];
	for(int i = 2;i <= m;i++){
		cnt = (cnt&a[i]);
	}cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
