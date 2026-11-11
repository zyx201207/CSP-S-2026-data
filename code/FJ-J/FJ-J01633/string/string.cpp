#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
		}
		int f = min(a[l],a[r]);
		a[l]-=f;
		a[r]-=f;
		if(a[l]<=0)l++;
		if(a[r]<=0)r--;
	}
	cout << ans;
	return 0;
}
