#include<bits/stdc++.h>
using namespace std;
int a[200005],c[200005];
char b[200005],d[200005],e[20005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,lena,ans = 0;
	cin >> n;
	for(int j = 1;j<=n;j++){
		cin >> a[j];
		cin >> b[j];
    }
	if(n==1){
		cout << 0;
		return 0;
	}

	for(int j = n;j>=1;j--){
		c[n-j+1] = a[j];
		d[n-j+1] = b[j];
	}
	if(n==2){
		if(d[1] != b[1]){
			if(a[1] >= c[1]){
				ans += c[1];
			}else{
				ans += a[1];
			}
		}
		cout << ans;
		return 0;
	}
	cout << ans;
}
