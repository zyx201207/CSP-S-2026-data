#include<bits/stdc++.h>
using namespace std;
int n,a[10],ans=5;
char r[10];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i] >> r[i];
		ans=min(a[i],ans);
	}
	if(n==1) cout << 0;
	if(n==2){
		if(r[1]==r[2]){
			cout << 0;
		}else cout << ans;
	}
	return 0;
}
