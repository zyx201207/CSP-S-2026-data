#include<bits/stdc++.h>
using namespace std;
int n,a[200005],cnt=1,ans;
char ch[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cin >> ch[i];
	}
	if(n==1){
		cout << 0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c[cnt++]=ch[i];
		}
	}
	for(int i=1;i<=cnt-1;i++){
		if(c[i]!=c[cnt-i]){
			ans++;
			c[i]=c[cnt-i];
		}
	}
	cout << ans;
	return 0;
}
