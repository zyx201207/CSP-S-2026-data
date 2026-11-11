#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	int last = 0;
	long a[500001] = {};
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 0 ;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans = 0;
	for(int i = 0 ;i<n;i++){
		ans = 0;
		for(int j = 0;j<n/2+i;j++){
			ans += a[n/2+i]-a[j];
		}
		if(ans >= m){
			last = n/2+i;
			if(ans>m) last--;
			for(int j = n/2+i;j<n;j++){
				if(a[j] == a[n/2+i]) last++;
			}
			break;
		}
	}
	printf("%d",last);
	return 0;
} 