#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
struct node{
	int num;
	int sl;
}a[200005];
int zh(int a){
	int cnt = 0;
	while(a){
		if(a%2 == 1) cnt ++;
		a /= 2;
	}
	return cnt;
}
bool cmp(node a,node b){
	if(a.sl == b.sl ) return a.num > b.num ;
	else return a.sl > b.sl;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i].num;
		a[i].sl = zh(a[i].num);
	}
	sort(a+1,a+n+1,cmp);
	ans = a[1].num ;
	for(int i = 2 ; i <= m ; i ++)
	{
		ans = (ans & a[i].num);
	}
	cout << ans;
	return 0;
}
