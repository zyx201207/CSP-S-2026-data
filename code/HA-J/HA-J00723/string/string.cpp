#include <bits/stdc++.h>
using namespace std;
long long n,a[200009],sum[200009],ans;
string c[200009],s[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	for (int t=1;t<=100;t++){
		for (int i=1,j=0;i<=n;i++){
			if (a[i-j]!=a[n-i+1]){
				sum[i]=min(a[i-j],a[n-i+1]);
				s[i]=c[i-j];
				if (a[i-j]>sum[i]){
					sum[i+1]=a[i-j]-sum[i];
					s[i+1]=c[i-j];
					j++;
					i++;
					n++;
				}
			}else {
				sum[i]=a[i-j];
				s[i]=c[i-j];
			}
		}
		for (int i=1;i<=n;i++){
			a[i]=sum[i];
			c[i]=s[i];
		}
	}
	for (int i=1;i<=n;i++){
		if (s[i]!=s[n-i+1]){
			ans+=sum[i];
		}
	}
	cout << ans/2;
	return 0;
}
