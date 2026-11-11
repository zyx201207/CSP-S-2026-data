#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005],cnt=0;
	char c[200005];
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	for(int l=1,r=n;l<r;){
		if(c[l]!=c[r]){
			if(a[l]>=a[r]){
				cnt+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				cnt+=a[l];
				a[r]-=a[l];
				l++;
			}
		}else{
			if(a[l]>=a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout << cnt;
	return 0;
} 
