#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,a[200001],t;
bool cmp(int y,int z){
	return y>z;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> x;
	for(int i = 1;i <= n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(x == 0){
		cout << 0;
	}
	int u=1;
	while(t == 0){
		t=a[u];
	//	for(int i = 1;i <= x+1;i++){
	//		cout << a[i] << " ";
	//	}
		for(int i = u;i <= x+u-1;i++){
			t=t&a[i];
		}
		u++;
	}
	cout << t;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
