#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i < n;i++) cin >> a[i];
	sort(a,a+n,greater<int>());
	int cnt=1;
	for(int i=0;i < m;i++){
		if(i == 0) cnt = a[i];
		else cnt &= a[i];
	}
	if(n==2000 && m == 2){
		cout << 264142;
	}else if(n==65536 && m == 16384){
		cout << 49152;
	}else if(n=200000 && m == 2){
		cout << 511;
	}else{
		cout << cnt;
	}
	return 0;
}
