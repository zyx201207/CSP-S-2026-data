#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){
	return x<y;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	int n, m;
	cin>>n>>m;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1, a+n+1, cmp);
	if(m==2){
		if(a[n-1]%2==0){
			cout<<(a[n-1]&a[n]);
		}else{
			cout<<(a[n-2]&a[n-1]);
		}
	}else{
		int cnt=a[n-m];
		for(int i=n-m+1;i<=n;i++){
			cnt=(cnt&a[i]);
		}
		cout<<cnt;
	}
	return 0;
}

