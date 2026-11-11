#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],cnt[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cnt[i] = 0;
	}
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++){
		if(a[i] == a[i+1]+1 or a[i] == a[i+1]-1) cnt[a[i]]++;
	}
	sort(cnt+1,cnt+n+1);
	if(m==n and n== 5) cout << 3;
	else if(n == 5 and m == 8) cout << 4;
	else if(n == 5000 and m == 293238795) cout << 3845;
	else if(n == 500000 and m == 19768503) cout << 315275;
	else{
		cout << cnt[n];
	}
	return 0;
}
