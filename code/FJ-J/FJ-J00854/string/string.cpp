#include<bits/stdc++.h>
using namespace std;

long long a[200010];
char c[200010];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	for (int i = 1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if (c[l]!=c[r]){
			if (a[l] > a[r]){
				c[r] = c[l];
				ans+=a[r];
			}
			else{
				c[l] = c[r];
				ans+=a[l];
			}
		}
		if (a[l] != a[r] && l+1<r){
			int x = a[l]-a[r];
			a[r-1]-=x;
			a[r]+=x;
			ans+=x;
		}
		l++;
		r--;
	}
	cout << ans;
	return 0;
}
