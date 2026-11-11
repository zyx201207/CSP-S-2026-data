#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]<=a[r]){
				a[r]-=a[l];
				l++;
				if(a[r]==0) r--;
			}
			else{
				a[l]-=a[r];
				r--;
				if(a[l]==0) l++;
			}
		} 
		else{
			if(a[l]<=a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
				if(a[r]==0) r--;
			}
			else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
				if(a[l]==0) l++;
			}
		}
	}
	cout << ans;
	return 0;
}
/*
100+100
Trick||Treat!!!
while(1) RP++; 
*/

