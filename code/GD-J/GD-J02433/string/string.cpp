#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans,len,a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++)
		cin>>a[i]>>c[i],len += a[i];
	int j = n;
	for (int i = 1;i <= j && len > 0;i++){
		len -= a[i] * 2;
		ll len2 = 0;
		while (len2 + a[j] < a[i]) {
			if (c[i] != c[j]) c[j] = c[i],ans += a[j];
			len2 += a[j--];
		}
		if (len2 < a[i]){
			if (c[i] != c[j]) 
				ans += a[j] - (len2 + a[j] - a[i]);
			a[j] = (len2 + a[j] - a[i]);
			if (!a[j]) j--;
		}
	}
	cout<<ans;
	return 0;
} 
