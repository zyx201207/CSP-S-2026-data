#include<bits/stdc++.h>
using namespace std;
int a[50005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,nn = 0;
	long long m;
	cin >> n >> m;
	int sum = m;
	int ans = 0;
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n%2 == 0){
		nn = n/2;
	}else{
		nn=n/2+1;
	} 
	for(int i = 1;i <= nn;i++){
		cnt = cnt+a[i];

	} 
	sum += cnt;
	for(int i = 1;i <= nn;i++){
	
		
		if(i = nn){
			if(a[nn] == a[nn+1]){
				ans = (sum+a[nn+1])/a[nn];
			}else{
				ans = sum/a[i];
			}
			
}
	}
	cout << ans;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
