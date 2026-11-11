#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005],str[1000000000];
int ans;
int main(){
	int lastst=1;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	bool flag1=1;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		if(c[i]!=c[i-1]&&i>1) flag1=0;
		for(int j=1;j<=a[i];j++){
			str[lastst]=c[i];
			lastst++;
		}
	}
	if(flag1==1) {cout << 0;return 0;}
	if(n==1) {cout << 0;return 0;}
	int j=n;
	for(int i=1;i<=lastst;i++){
		if(c[i]!=c[j]) ans+=min(a[i],a[j]);
		j--;
	}
	cout << ans;
	return 0;
}
