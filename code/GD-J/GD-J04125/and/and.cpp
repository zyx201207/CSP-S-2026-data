#include<bits/stdc++.h>
using namespace std;
int n,m;
long long num,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin >> n >> m;
	long long a[m+5];
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		
	}
	for(int i = 1;i<=n-1;i++){
		num = a[i]&&a[i+1];
		if(num = a[i])
			num = a[i-1];
		else
			num = a[i];
		ans = max(ans,num);
	}
	cout << ans;
}
