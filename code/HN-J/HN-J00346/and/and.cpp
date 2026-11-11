#include<bits/stdc++.h>
using namespace std;
int n,m,minn;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	if(n == 1){
		cout << a[1];
		return 0;
	}
	else if(n == 2){
		if(m == 1)   cout << max(a[1],a[2]);
		if(m == 2)   cout << min(a[1],a[2]);
		return 0;
	}
	for(int i = 1;i <= n;i++){
		minn = min(a[i],a[i - 1]);
	}
	cout << minn;


	return 0;
}

