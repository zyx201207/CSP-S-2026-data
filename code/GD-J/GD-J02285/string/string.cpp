#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
char c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	long long ans=0;
	for (int i=1,j=n;i<j;){
		if (c[i]!=c[j]){
			if (a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
			else if (a[i]==a[j]){
				ans+=a[i];
				i++,j--;
			}
			else {
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
		}
		else {
			if (a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}
			else if (a[i]==a[j]){
				i++,j--;
			}
			else {
				a[i]-=a[j];
				j--;
			}
		} 
	}
	cout << ans;
	return 0;
}
