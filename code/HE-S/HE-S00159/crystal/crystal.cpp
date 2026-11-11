#include <bits/stdc++.h>
using namespace std; 
int a[5000010];
long long n,m;
int x,cnt;
bool cmp(long x,long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(long long i = 1;i <= n;i++){
		for(long long j = 1;j <= m;j++){
		if(a[x] == a[i] || a[x] == a[i-1]){
		cnt++;
	}
	cnt = 0;
	}
}
for(long i = 1;i <= m;i++){
	if(a[x] != a[i-1]){
		a[x]++;
}
		if(a[x] == a[i-1]){
			cnt++;
		
	}
}
	cout << cnt;
	return 0;
}
