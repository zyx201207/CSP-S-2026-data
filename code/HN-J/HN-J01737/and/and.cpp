#include <bits/stdc++.h>

using namespace std;

const int N=3e5+10;
unsigned long long n,m;
int a[N];
bool cmp(int x,int y){
	bool flag=0;
	int zx=x,zy=y;
	int zw=0,yw=0;
	while(zx){
		zx=zx>>1;
		zw++;
	}
	while(zy){
		zy=zy>>1;
		yw++;
	}
	for(int i=1;i<=max(zw,yw);i++){
		if(x%2>y%2) flag=1;
		if(x%2<y%2) flag=0; 
		x=x>>1;
		y=y>>1;
	}
	if(flag){
		return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	int res=a[0];
	for(int i=1;i<m;i++){
		res=res&a[i];
	}
	cout << res;
	return 0;
}
